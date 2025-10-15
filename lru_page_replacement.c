#include <stdio.h>

int findLRU(int time[], int n) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames, pages, page[30], frame[10], time[10], count = 0, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    printf("Enter number of pages: ");
    scanf("%d", &pages);
    printf("Enter reference string: ");
    for (int i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");
    for (int i = 0; i < pages; i++) {
        int flag1 = 0, flag2 = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == page[i]) {
                count++;
                time[j] = count;
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    count++;
                    frame[j] = page[i];
                    time[j] = count;
                    faults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            int pos = findLRU(time, frames);
            count++;
            frame[pos] = page[i];
            time[pos] = count;
            faults++;
        }

        printf("%d\t", page[i]);
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
