#include <stdio.h>

int main() {
    int n, bt[20], p[20], pr[20], wt[20], tat[20], i, j, pos, temp;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i+1;
    }

    // Sort by priority
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i+1; j < n; j++) {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i]; pr[i] = pr[pos]; pr[pos] = temp;
        temp = bt[i]; bt[i] = bt[pos]; bt[pos] = temp;
        temp = p[i]; p[i] = p[pos]; p[pos] = temp;
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        awt += wt[i];
    }

    printf("\nProcess\tBT\tPriority\tWT\tTAT");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        atat += tat[i];
        printf("\nP%d\t%d\t%d\t\t%d\t%d", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt/n);
    printf("\nAverage Turnaround Time = %.2f\n", atat/n);
    return 0;
}

