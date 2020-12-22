#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//deklarasi
void *printPesan( void *ptr );

int main()
{
     pthread_t thread1, thread2;
     char *message1 = "Halo dari thread 1";
     char *message2 = "Halo dari thread 2";
     int  iret1, iret2;

     /* buat 2 threads  */

     iret1 = pthread_create( &thread1, NULL, printPesan, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, printPesan, (void*) message2);

     /* tunggu, jika tidak ditunggu maka akan langsung selesai  */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread 1 selesai dgn return: %d\n",iret1);
     printf("Thread 2 selesai dgn return: %d\n",iret2);
     exit(0);
}

void *printPesan( void *ptr )
{
     char *message;
     message = (char *) ptr; //casting
     printf("%s \n", message);
}
