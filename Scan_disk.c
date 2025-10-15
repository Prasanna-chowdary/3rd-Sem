#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, temp, distance = 0, dir;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0: left, 1: right): ");
    scanf("%d", &dir);

    // Sort the request array
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }

    int idx = 0;
    while(idx < n && req[idx] < head) idx++;

    printf("\nHead movements:\n");

    if(dir == 1) { // moving right
        for(i = idx; i < n; i++) {
            printf("%d -> ", req[i]);
            distance += abs(req[i] - head);
            head = req[i];
        }
        for(i = idx-1; i >= 0; i--) {
            printf("%d -> ", req[i]);
            distance += abs(req[i] - head);
            head = req[i];
        }
    } else { // moving left
        for(i = idx-1; i >= 0; i--) {
            printf("%d -> ", req[i]);
            distance += abs(req[i] - head);
            head = req[i];
        }
        for(i = idx; i < n; i++) {
            printf("%d -> ", req[i]);
            distance += abs(req[i] - head);
            head = req[i];
        }
    }

    printf("End\nTotal Head Movement = %d\n", distance);
    return 0;
}
