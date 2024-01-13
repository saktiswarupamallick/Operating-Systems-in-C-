int main(){
    fork() && fork();
    fork() || fork();
    printf("Hi\n");
    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>