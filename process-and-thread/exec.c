#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv){
    char *args[] = {"ls", "-aF", "/", 0};   /* parameter command line */
    char *env[] = { 0 };    /* environment list null */

    printf("Akan menjalankan /bin/ls\n");
    execve("/bin/ls", args, env);
    perror("execve");
    exit(1);
}