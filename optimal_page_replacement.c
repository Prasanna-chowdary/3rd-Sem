#include <stdio.h>

int main() {
    int frames, pages, page[30], frame[10], count = 0, faults = 0;
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
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0) {
            for (int j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = page[i];
                    faults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        if (flag2 == 0) {
            int pos = -1, farthest = i+1;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i+1; k < pages; k++) {
                    if (frame[j] == page[k]) {
                        if (k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }
                if (k == pages) { // page not used in future
                    pos = j;
                    break;
                }
            }
            frame[pos] = page[i];
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
