<h1>Efficient Print Queue Management System with Prioritization and Streamlit GUI</h1>

<p>This project presents an advanced solution for managing print jobs efficiently in modern computer systems. It combines the power of C programming for backend logic with a Python-based GUI created using Streamlit, providing an intuitive interface for managing print jobs while prioritizing them based on factors such as file size and urgency.</p>

<hr>

<h2>Table of Contents</h2>
<ol>
  <li><a href="#features">Features</a></li>
  <li><a href="#modules-overview">Modules Overview</a></li>
  <li><a href="#installation">Installation</a></li>
  <li><a href="#usage">Usage</a></li>
  <li><a href="#technologies-used">Technologies Used</a></li>
  <li><a href="#future-enhancements">Future Enhancements</a></li>
  <li><a href="#license">License</a></li>
  <li><a href="#acknowledgments">Acknowledgments</a></li>
</ol>

<hr>

<h2 id="features">Features</h2>

<ul>
  <li><strong>Multi-Job Handling:</strong> Supports handling multiple print jobs concurrently.</li>
  <li><strong>Dynamic Job Prioritization:</strong> Prioritizes print jobs based on criteria such as file size and urgency.</li>
  <li><strong>Priority Queue System:</strong> Utilizes a priority queue data structure in C to manage job execution order.</li>
  <li><strong>Real-Time GUI:</strong> Python Streamlit interface for easy user interaction and real-time updates on job status.</li>
  <li><strong>Error Handling:</strong> Robust error handling for job management, including file retrieval issues and queue overflow.</li>
  <li><strong>Job Sequence Handling:</strong> Processes print jobs sequentially based on their priority and sequence.</li>
</ul>

<hr>

<h2 id="modules-overview">Modules Overview</h2>

<h3>Backend - C Programming:</h3>
<ul>
  <li><strong>Priority Queue Implementation:</strong> C program defines a priority queue structure to store and manage print jobs.</li>
  <li><strong>Job Handling Functions:</strong> Functions to add jobs, calculate priorities, and process jobs sequentially based on priority.</li>
  <li><strong>Error Handling:</strong> Graceful error handling for scenarios like file retrieval failures or exceeding queue capacity.</li>
</ul>

<h3>Frontend - Python Streamlit GUI:</h3>
<ul>
  <li><strong>File Upload:</strong> Allows users to upload multiple print jobs (files) through a simple interface.</li>
  <li><strong>Job Status Display:</strong> Real-time updates showing the status of each print job in the queue.</li>
  <li><strong>Job Control:</strong> Provides buttons to process jobs, view queue status, and manage the print queue.</li>
  <li><strong>Interaction with C Backend:</strong> The GUI communicates with the C backend to handle job processing and display output in real-time.</li>
</ul>

<hr>

<h2 id="installation">Installation</h2>

<h3>Prerequisites</h3>
<ul>
  <li><strong>C Compiler:</strong> A C compiler such as GCC to compile the C backend.</li>
  <li><strong>Python:</strong> Python 3.x (for running the Streamlit GUI).</li>
  <li><strong>Streamlit Library:</strong> Streamlit library for the Python GUI interface. Install with <code>pip install streamlit</code>.</li>
  <li><strong>Operating System:</strong> This project is designed to work on both Windows and Linux-based systems.</li>
</ul>

<h3>Setup Steps</h3>
<ol>
  <li>Clone the repository:
    <pre><code>git clone https://github.com/your-username/print-queue-management.git
cd print-queue-management</code></pre>
  </li>
  <li>Compile the C code:
    <pre><code>gcc -o print_queue print_queue.c</code></pre>
  </li>
  <li>Install the necessary Python libraries for the GUI:
    <pre><code>pip install streamlit</code></pre>
  </li>
  <li>Run the Streamlit application:
    <pre><code>streamlit run app.py</code></pre>
  </li>
  <li>Access the GUI through your browser at the provided localhost URL.</li>
</ol>

<hr>

<h2 id="usage">Usage</h2>

<h3>Backend - C Program:</h3>
<ul>
  <li>Upon running the C program, the system initializes the print queue with a set of predefined priorities.</li>
  <li>Print jobs are added to the queue and processed based on their priority, file size, and urgency.</li>
  <li>Job details (filename, size, added time, etc.) are displayed as the program executes.</li>
</ul>

<h3>Frontend - Streamlit GUI:</h3>
<ul>
  <li>Users can upload print job files via the Streamlit interface, which are then sent to the C backend for processing.</li>
  <li>The interface provides real-time updates on the status of each job in the queue.</li>
  <li>Users can manually trigger the print job processing using the provided control buttons.</li>
  <li>Displays a list of all jobs currently in the queue with their processing status.</li>
</ul>

<p>For a visual representation of the system and its modules, please refer to the <strong>"screenshots"</strong> folder in the repository, which contains images of each module and the corresponding UI.</p>

<hr>

<h2 id="technologies-used">Technologies Used</h2>

<ul>
  <li><strong>C Programming:</strong> Core backend logic for managing the print queue and job prioritization.</li>
  <li><strong>Streamlit:</strong> Python library used for creating the GUI to interact with the backend.</li>
  <li><strong>GCC:</strong> C compiler for compiling the backend code.</li>
  <li><strong>Operating System:</strong> Compatible with Windows and Linux-based operating systems.</li>
</ul>

<hr>

<h2 id="future-enhancements">Future Enhancements</h2>

<ul>
  <li><strong>Cloud Integration:</strong> Enable the system to work with cloud-based storage for print jobs and resources.</li>
  <li><strong>User Authentication:</strong> Add a user authentication mechanism to restrict access to the print queue system.</li>
  <li><strong>Job Scheduling Optimization:</strong> Implement more sophisticated algorithms for job scheduling based on additional factors.</li>
  <li><strong>Mobile Interface:</strong> Create a mobile-friendly interface for managing print jobs on-the-go.</li>
  <li><strong>Advanced Error Handling:</strong> Improve error detection and recovery mechanisms for edge cases.</li>
</ul>

<hr>

<h2 id="license">License</h2>

<p>This project is licensed under the MIT License. See the <a href="LICENSE">LICENSE</a> file for details.</p>

<hr>

<h2 id="acknowledgments">Acknowledgments</h2>

<p>We would like to thank the contributors, mentors, and all those who supported the development of this project. Special thanks to the open-source community for the tools and libraries that made this project possible.</p>
