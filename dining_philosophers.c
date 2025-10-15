#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of philosophers: ");
    scanf("%d", &n);
    int chopstick[n];

    for (int i = 0; i < n; i++)
        chopstick[i] = 1; // all free

    printf("\nPhilosophers try to eat:\n");
    for (int i = 0; i < n; i++) {
        if (chopstick[i] && chopstick[(i+1)%n]) {
            chopstick[i] = chopstick[(i+1)%n] = 0;
            printf("Philosopher %d starts eating.\n", i+1);
            chopstick[i] = chopstick[(i+1)%n] = 1;
            printf("Philosopher %d finishes eating.\n", i+1);
        } else {
            printf("Philosopher %d can't eat now.\n", i+1);
        }
    }
    return 0;
}
