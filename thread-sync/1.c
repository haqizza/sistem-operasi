#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h>
  

int counter;
void *fung(void *vargp) 
{ 
    unsigned long i = 0;
    counter += 1;
    printf("\n Job %d mulai\n", counter);
    for(i=0; i<(99999999);i++);  //task yang lama
    printf("\n Job %d selesai\n", counter);
    return NULL; 
} 
   
int main() 
{ 
    pthread_t t1,t2; 
    pthread_create(&t1, NULL, fung, NULL); 
    pthread_create(&t2, NULL, fung, NULL);

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 
    exit(0); 
}
