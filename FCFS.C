#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], i, j;
    float awt = 0, atat = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    printf("\nProcess\tBT\tWT\tTAT");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        awt += wt[i];
        atat += tat[i];
        printf("\nP%d\t%d\t%d\t%d", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f\n", atat/n);
    return 0;
}
