#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], i, j, n, temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    // Sort based on burst time
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (bt[j] > bt[j+1]) {
                temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = p[j]; p[j] = p[j+1]; p[j+1] = temp;
            }
        }
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
        printf("\nP%d\t%d\t%d\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f\n", atat/n);
    return 0;
}
