#include <stdio.h>

int main() {
    int n, m, i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &n);
    int block[n];
    printf("Enter block sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &m);
    int process[m];
    printf("Enter process sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &process[i]);

    int allocation[m];
    for(i = 0; i < m; i++)
        allocation[i] = -1; // no allocation yet

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(block[j] >= process[i]) {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No\n");
    for(i = 0; i < m; i++) {
        printf("%d\t\t%d\t\t", i+1, process[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i]+1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
