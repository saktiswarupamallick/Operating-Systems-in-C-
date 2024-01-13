#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Shared variable
    int *shrd = malloc(sizeof(int));
    *shrd = 0;

    // Forking
    pid_t pid = fork();

    if (pid == 0) {
        // Child process (P-1)
        int x;
        x = *shrd;
        x = x + 1;
        sleep(1);
        *shrd = x;
        printf("P-1: *shrd = %d\n", *shrd);
    } else if (pid > 0) {
        // Parent process (P-2)
        int y;
        y = *shrd;
        y = y - 1;
        sleep(1);
        *shrd = y;
        printf("P-2: *shrd = %d\n", *shrd);
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    // Free allocated memory
    free(shrd);

    return 0;
}
