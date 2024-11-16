import os
import subprocess
import time
import streamlit as st

MAX_JOBS = 10

def main():
    st.title("Print Queue Management System")
    
    # Directory to store uploaded files
    upload_dir = "uploaded_files"
    if not os.path.exists(upload_dir):
        os.makedirs(upload_dir)
    
    uploaded_files = st.file_uploader("Choose files", accept_multiple_files=True)
    if uploaded_files:
        # Save uploaded files to disk
        file_paths = []
        for uploaded_file in uploaded_files:
            file_path = os.path.join(upload_dir, uploaded_file.name)
            with open(file_path, "wb") as f:
                f.write(uploaded_file.getbuffer())
            file_paths.append(file_path)

        

        # Pass the file paths to the C program
        num_files = len(file_paths)
        if num_files > MAX_JOBS:
            st.write(f"Number of files exceeds the maximum limit of {MAX_JOBS}.")
            return

        command = ["./print_queue", str(num_files)] + file_paths
        result = subprocess.run(command, capture_output=True, text=True)
        
        # Display the output of the C program
        st.text(result.stdout)
        st.text(result.stderr)
        
        
        # Option to process print jobs
        if st.button("Process Print Jobs"):
            result = subprocess.run(["./print_queue", str(num_files)] + file_paths, capture_output=True, text=True)
            st.text(result.stdout)
            st.text(result.stderr)

if __name__ == "__main__":
    main()
