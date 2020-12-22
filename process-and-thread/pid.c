#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    printf("PID saya: %d. Parentnya: %d\n", getpid(), getppid());
    sleep(200);
    exit(0);
}