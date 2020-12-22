#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h> 
  
//perhatikan * sebelum nama fungsi 
void *myThread(void *vargp) 
{ 
    sleep(1); 
    printf("Halo dari dalam Thread \n"); 
    return NULL; 
} 
   
int main() 
{ 
    pthread_t thread_id; 
    printf("sebelum Thread\n"); 
    //buat thread
    pthread_create(&thread_id, NULL, myThread, NULL); 

    //tunggu thread selesai, jika tdk ada join, maka akan langsung exit
    pthread_join(thread_id, NULL); 
    printf("sesudah Thread\n"); 
    exit(0); 
}
