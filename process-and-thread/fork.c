#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <curses.h>

int main(int argc, char **argv){
    int pid,pid2;
    printf("mulai\n");

    switch (pid = fork()){
        case 0: /* fork returns 0 ke proses anak */
                printf("process anak pertama: pid = %d\n",getpid());
                pid2 = fork();
                if(pid2 == 0){
                    printf("ini adalah proses anak level dua\n");
                    printf("anak kedua ini punya pid = %d\n",getpid());
                }
                else if(pid2 == -1){
                    perror("error");
                    exit(1);
                }
                else{
                    printf("anak pertama ...\n");         
                }
                break;
        default: /* fork returns pid ke proses ortu */
                printf("process parent: pid = %d, anak pid=%d\n",getpid(), pid);
                break;
        case -1: /* error */
                perror("fork");
                exit(1);                
    }

    //Catatan UTS
    // int p = fork(), p2;
    // int pa,pb,pc,pd,pe,pf,pg,ph;
    
    // if(p != 0){
    //     pa = getppid();
    //     pb = getpid();
    //     printf("1 a b = %d %d\n",pa,pb);
    //     p2=fork();
    //     if(p2 != 0){
    //         pe = getppid();
    //         pf = getpid();
    //         printf("2 ae f =%d %d\n",pe,pf);
    //     }else{
    //         pg = getppid();
    //         ph = getpid();
    //         printf("2 g h =%d %d\n",pg,ph);
    //     }
    // }else{
    //     pc = getppid();
    //     pd = getpid();
    //     printf("1 c d=  %d %d\n",pc,pd);
    // }
    // 1 a b = 37762 46344
    // 1 c d =  46344 46345
    // 2 e f = 37762 46344
    // 2 g h = 46344 46346

    exit(0);
}