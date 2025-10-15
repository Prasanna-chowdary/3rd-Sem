#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, j, temp, distance = 0, max, min = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the request sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter maximum cylinder number: ");
    scanf("%d", &max);

    // Sort the requests
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

    // Move towards right first
    for(i = idx; i < n; i++) {
        printf("%d -> ", req[i]);
        distance += abs(req[i] - head);
        head = req[i];
    }

    // Move to end and wrap around
    distance += abs(max - head);
    head = min; // wrap to start
    printf("%d -> ", head);

    for(i = 0; i < idx; i++) {
        printf("%d -> ", req[i]);
        distance += abs(req[i] - head);
        head = req[i];
    }

    printf("End\nTotal Head Movement = %d\n", distance);
    return 0;
}
