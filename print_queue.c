#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // For sleep function

#define MAX_JOBS 10
#define MAX_FILENAME_LENGTH 256

typedef struct 
{
    char name[MAX_FILENAME_LENGTH];
    long size;
    time_t added_time;
    int priority;
    int sequence;
}PrintJob;

typedef struct 
{
    PrintJob jobs[MAX_JOBS];
    int size;
} PriorityQueue;

void add_to_queue(PriorityQueue *queue, PrintJob job) 
{
    if (queue->size < MAX_JOBS)
   {
       

       queue->jobs[queue->size] = job;
        queue->size++;
    } 
   else 
  {
        printf("Queue is full. Cannot add more print jobs.\n");
    }
}

void calculate_priority(PrintJob *job, long min_size, long max_size)
 {
    int priority_range = 10;
    // Calculate priority such that smaller files get higher priority
    int priority = 1 + (int)(((double)(max_size - job->size) / (double)(max_size -      min_size)) * (priority_range - 1));
    job->priority = priority;
}

void assign_priority(PriorityQueue *queue) 
{
    if (queue->size == 0) 
   {
        return;
    }

    long min_size = queue->jobs[0].size;
    long max_size = queue->jobs[0].size;
    for (int i = 1; i < queue->size; i++) 
   {
       

        if (queue->jobs[i].size < min_size) 
       {
            min_size = queue->jobs[i].size;
        }
        if (queue->jobs[i].size > max_size) 
       {
            max_size = queue->jobs[i].size;
        }
    }

    for (int i = 0; i < queue->size; i++) 
   {
        calculate_priority(&queue->jobs[i], min_size, max_size);
        queue->jobs[i].sequence = i;
    }
}

void sort_jobs(PriorityQueue *queue) 
{
    for (int i = 0; i < queue->size - 1; i++) 
   {
        for (int j = 0; j < queue->size - 1 - i; j++) 
       {
            if (queue->jobs[j].priority < queue->jobs[j + 1].priority ||
         (queue->jobs[j].priority == queue->jobs[j + 1].priority && queue->jobs[j].sequence > queue->jobs[j + 1].sequence)) 
{
                PrintJob temp = queue->jobs[j];
                


               queue->jobs[j] = queue->jobs[j + 1];
                queue->jobs[j + 1] = temp;
  }
        }
    }
}

void print_queue(PriorityQueue *queue) 
{
    printf("Queue:\n");
    for (int i = 0; i < queue->size; i++) 
   {
        printf("Job ID: %d, File: %s, Size: %ld, Added Time: %s, Priority: %d\n",
               i, queue->jobs[i].name, queue->jobs[i].size, ctime(&queue->jobs[i].added_time),
               queue->jobs[i].priority);
    }
}

void process_print_jobs(PriorityQueue *queue) 
{
    sort_jobs(queue);
    int k = 0;
    while (queue->size > 0) 
   {
        PrintJob job = queue->jobs[0];
        printf("Processing Job ID: %d, File: %s, Size: %ld, Priority: %d\n", k, job.name, job.size, job.priority);
        k = k + 1;
        

       for (int i = 1; i < queue->size; i++) 
       {
            queue->jobs[i - 1] = queue->jobs[i];
            

            queue->jobs[i - 1].sequence = i - 1;
        }
        queue->size--;
        sleep(1);
    }
}

long get_file_size(const char *filename) 
{
    FILE *file = fopen(filename, "rb");
    if (!file) 
    {
        printf("Error: Could not open file %s\n", filename);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size;
}

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
   {
        printf("Usage: %s <number_of_files> <file_names...>\n", argv[0]);
        return 1;
    }

    

    int num_files = atoi(argv[1]);
    if (num_files <= 0 || num_files > MAX_JOBS) 
   {
        printf("Invalid number of files. Must be between 1 and %d.\n", MAX_JOBS);
        return 1;
    }

    if (argc < num_files + 2) 
   {
        printf("Usage: %s <number_of_files> <file_names...>\n", argv[0]);
        return 1;
    }

    PriorityQueue queue = { .size = 0 };

    for (int i = 0; i < num_files; i++) 
   {
        PrintJob job;
        strncpy(job.name, argv[i + 2], MAX_FILENAME_LENGTH);
        job.size = get_file_size(argv[i + 2]);
        if (job.size < 0) 
       {
            printf("Skipping file %s due to size retrieval error.\n", argv[i + 2]);
            continue;
        }
        job.added_time = time(NULL);
        add_to_queue(&queue, job);
    }


    assign_priority(&queue);
    print_queue(&queue);
    process_print_jobs(&queue);

    return 0;
}
