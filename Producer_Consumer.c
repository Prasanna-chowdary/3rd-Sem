#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty, x = 0;

int wait(int s) { return (--s); }
int signal(int s) { return (++s); }

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("Producer produces item %d\n", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("Consumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}

int main() {
    int n;
    printf("Enter buffer size: ");
    scanf("%d", &empty);
    while (1) {
        printf("\n1.Produce  2.Consume  3.Exit\n");
        scanf("%d", &n);
        switch(n) {
            case 1:
                if (mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is Full!\n");
                break;
            case 2:
                if (mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is Empty!\n");
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}
