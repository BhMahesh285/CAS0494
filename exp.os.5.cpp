#include <stdio.h>
int main() {
    int bt[20], p[20], wt[20], tat[20], n, total = 0, pos, temp;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter number of processes:");
    scanf("%d", &n);
    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("p%d:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }
        temp = bt[i]; bt[i] = bt[pos]; bt[pos] = temp;
        temp = p[i]; p[i] = p[pos]; p[pos] = temp;
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("p%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    avg_wt = (float)total / n;
    avg_tat = (float)total / n;
    printf("\nAverage Waiting Time= %f", avg_wt);
    printf("\nAverage Turnaround Time= %f\n", avg_tat);
    return 0;
}
