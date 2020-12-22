#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h> 
  
int counter;
pthread_mutex_t lock;

void *fung(void *vargp) 
{ 
    pthread_mutex_lock(&lock); //lock
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d mulai\n", counter);
    for(i=0; i<(99999999);i++);  //task yang lama
    printf("\n Job %d selesai\n", counter);

    pthread_mutex_unlock(&lock); //unlock
    return NULL; 
} 

   
int main() 
{ 
    pthread_t t1,t2; 

    //init mutex
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n mutex init gagal\n");
        return 1;
    }

    pthread_create(&t1, NULL, fung, NULL); 
    pthread_create(&t2, NULL, fung, NULL);
    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 

    //destroy mutex
    pthread_mutex_destroy(&lock);
    exit(0); 
}
