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

    int j = 0;
    printf("\nPage\tFrames\n");
    for (int i = 0; i < pages; i++) {
        int flag = 0;
        for (int k = 0; k < frames; k++) {
            if (frame[k] == page[i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            frame[j] = page[i];
            j = (j + 1) % frames;
            faults++;
        }

        printf("%d\t", page[i]);
        for (int k = 0; k < frames; k++) {
            if (frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
