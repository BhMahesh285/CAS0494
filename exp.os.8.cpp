#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int remainingTime;
};

void schedule(struct Process processes[], int n, int quantum) {
    int i, remainingProcesses = n, time = 0;

    while (remainingProcesses > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime > quantum) {
                    time += quantum;
                    processes[i].remainingTime -= quantum;
                    printf("Process %d is running at time %d\n", processes[i].id, time);
                } else {
                    time += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                    printf("Process %d completed at time %d\n", processes[i].id, time);
                    remainingProcesses--;
                }
            }
        }
    }
}

int main() {
    int n, quantum, i;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[n];
    
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }
    
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    
    schedule(processes, n, quantum);
    
    return 0;
}
