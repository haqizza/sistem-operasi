#include <stdlib.h>     /* exit() */
#include <unistd.h>     /* fork() and getpid() */
#include <stdio.h>      /* printf() */
#include <string.h>

#define MSGSIZE 3

int main(int argc, char **argv) {
    char inbuf[MSGSIZE]; //buffer
    int pid;
    int fd[2]; //pipe

    //create pipe
    if (pipe(fd) < 0) {
        exit(1); //error
    }
    printf("mulai \n");

    switch (pid = fork()) {
        case 0: /* fork returns 0 ke proses anak */
                printf("Proses anak \n");
                // tulis data ke pipe
                char* msg1  = "ini pesan child \0"; // simbol \0 adalah end of string
                char* msg2  = "pesan kedua ...  \0"; 
                /* tutup bagian input dari pipe */
                close(fd[0]);
                // tulis ke pipe
                write(fd[1], msg1, MSGSIZE);
                write(fd[1], msg2, MSGSIZE);

                int arrIntChild[MSGSIZE] = {5,4,3};
                write(fd[1], arrIntChild, sizeof(arrIntChild));
                break;
        default:        /* fork returns pid ke proses ortu */
                int arrIntParent[MSGSIZE];
                // baca yang ditulis child dari pipe
                read(fd[0], arrIntParent, sizeof(arrIntParent));
                for (int i = 0; i<MSGSIZE; i++) {
                    printf("proses child menulis: %d \n", arrIntParent[i]);
                }
                break;
        case -1:        /* error */
                perror("fork");
                exit(1);
        }
        exit(0);
}
