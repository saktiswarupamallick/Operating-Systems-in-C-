#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>

// Declare semaphore
sem_t sem;

void displayMessage(int processNumber, const char *message) {
    sem_wait(&sem);  // Wait for semaphore

    fprintf(stderr, "P%d: %s\n", processNumber, message);

    sem_post(&sem);  // Release semaphore
}

int main() {
    // Initialize semaphore with an initial value of 1
    sem_init(&sem, 0, 1);

    // Fork 5 child processes
    for (int i = 1; i <= 5; ++i) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            if (i == 1) {
                displayMessage(i, "Coronavirus");
            } else if (i == 2) {
                displayMessage(i, "WHO:");
            } else if (i == 3) {
                displayMessage(i, "COVID-19");
            } else if (i == 4) {
                displayMessage(i, "disease");
            } else {
                displayMessage(i, "pandemic");
            }

            exit(0);
        } else if (pid < 0) {
            fprintf(stderr, "Fork failed\n");
            return 1;
        }
    }

    // Parent process
    for (int i = 0; i < 5; ++i) {
        wait(NULL);  // Wait for each child to terminate
    }

    // Destroy semaphore
    sem_destroy(&sem);

    return 0;
}
