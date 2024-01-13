#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to calculate Fibonacci sequence
void generateFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Sequence for %d terms: ", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_terms>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);

    if (n < 0) {
        fprintf(stderr, "Number of terms must be non-negative.\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        generateFibonacci(n);
    } else {
        // Parent process
        wait(NULL); // Wait for the child to finish
        printf("Parent process is done.\n");
    }

    return 0;
}
