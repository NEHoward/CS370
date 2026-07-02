#include <stdio.h>

// design a FCFS scheduling algorithm
// read input from csv with scheduling parameters:

typedef struct {
    int pid, arrival, burst, priority;
    int completion, waiting, turnaround;
} Process;

int main(int argc, char *argv[]) {
    int n=0;
    Process p[100];

    if (argc < 2) {
        printf("Usage: %s <input_filename>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(f, "%d,%d,%d,%d", &p[n].pid, &p[n].arrival, &p[n].burst, &p[n].priority) == 4) {
        n++;
    }
    fclose(f);
    
    // sort processes by arrival time
    // serve earliest arrival first || bubble sort

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(p[j].arrival > p[j+1].arrival){
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j+1] = temp;
            }
        }
    }

    //sweep through the processes 
    //and calculate completion, waiting, and turnaround times

    int clock = 0;
    float total_waittime = 0.0, total_turnaround = 0.0;
    
    for (int i = 0; i <n; i++){
        //if the cpu is idle wating for process to arrive, tick clock forward
        if(clock < p[i].arrival){
            clock = p[i].arrival; 
        }

         // set completion time 
            //process to finish after running for its burst time
        p[i].completion = clock + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;
            
        clock = p[i].completion;

        total_waittime += p[i].waiting;
        total_turnaround += p[i].turnaround;
    }
        //find avg wait time, turnaround, and throughput 
        //by aggregating the set totals 
        //and dividing by the number of processes
        float avg_waittime = total_waittime/n;
        float avg_turnaround = total_turnaround/n;
        float throughput = (float)n / clock;

         //output statements
        printf("--- FCFS ---\n");
        printf("Average Turnaround Time: %.3f\n", avg_turnaround);
        printf("Average Waiting Time: %.3f\n", avg_waittime);
        printf("Throughput: %.3f\n", throughput);
    return 0;
}