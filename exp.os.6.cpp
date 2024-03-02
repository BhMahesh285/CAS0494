#include <stdio.h>
struct process {
    char name;
    int burst, wait, turnaround, priority;
};
int main() {
    int n, total = 0, pos;
    float avg_wait = 0, avg_turn = 0;
    printf("Enter the total number of Processes: ");
    scanf("%d", &n);
    struct process p[n], temp;
    for (int i = 0; i < n; i++) {
        p[i].name = 'A' + i;
        printf("\nEnter burst time and priority for process %c: ", p[i].name);
        scanf("%d%d", &p[i].burst, &p[i].priority);
    }
    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++)
            if (p[j].priority > p[pos].priority) pos = j;
        temp = p[i]; p[i] = p[pos]; p[pos] = temp;
    }
    p[0].wait = 0;
    for (int i = 1; i < n; i++) {
        p[i].wait = 0;
        for (int j = 0; j < i; j++) p[i].wait += p[j].burst;
        total += p[i].wait;
    }
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        p[i].turnaround = p[i].burst + p[i].wait;
        total += p[i].turnaround;
        printf("%c\t%d\t%d\t%d\n", p[i].name, p[i].burst, p[i].wait, p[i].turnaround);
    }
    avg_wait = (float)total / n;
    avg_turn = (float)total / n;
    printf("\nAvg Wait: %.2f\nAvg Turn: %.2f\n", avg_wait, avg_turn);
    return 0;
}
