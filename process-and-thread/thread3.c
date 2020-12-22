#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h> 
  

int globVar = 0;
 
void *fungsi1(void *vargp) 
{ 
    printf("Isi variabel global = %d\n",globVar);
    globVar = 1;
    printf("Set variabel global dengan 1\n");
    return NULL; 
} 

void *fungsi2(void *vargp)
{
   printf("Isi variabel global = %d\n",globVar);
   globVar = 2;
   printf("Set variabel global dengan 2\n");
   return NULL;
}
   
int main() 
{ 
    pthread_t thread_id1,thread_id2; 
    printf("sebelum Thread\n"); 
    //buat thread
    pthread_create(&thread_id1, NULL, fungsi1, NULL); 
    pthread_create(&thread_id2, NULL, fungsi2, NULL);
    //tunggu thread selesai, jika tdk ada join, maka akan langsung exit
    pthread_join(thread_id2, NULL); 
    pthread_join(thread_id1, NULL);
    printf("sesudah Thread\n");
    printf("Variabel global = %d\n",globVar); 
    exit(0); 
}
