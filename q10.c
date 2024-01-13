#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t childpid;

    childpid = fork(); // Create a child process

    if (childpid == -1) {
        perror("Failed to fork");
        return 1;
    }

    if (childpid == 0) {
        // Child code
        printf("I am child %ld\n", (long)getpid());
    } else {
        // Parent code
        printf("I am parent %ld\n", (long)getpid());
    }

    return 0;
}
