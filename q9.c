#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void generateFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Sequence for %d terms: ", n);

    for (int i = 0; i < n; ++i) {
        printf("%d, ", first);
        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number_of_terms>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        fprintf(stderr, "Please provide a positive number of terms.\n");
        return 1;
    }

    pid_t childpid;

    childpid = fork();

    if (childpid == -1) {
        perror("Failed to fork");
        return 1;
    }

    if (childpid == 0) {  // Child process
        generateFibonacci(n);
    } else {  // Parent process
        wait(NULL);  // Wait for the child process to complete
        printf("Parent process is done.\n");
    }

    return 0;
}
