#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h> 

int counter;
pthread_mutex_t lock;

void *fung1(void *vargp) 
{   
    pthread_mutex_lock(&lock);
    counter++;

    for(int i =0; i < 1000; i++)
    {
        
        printf("%s","X");
        
    }  //task yang lama
    
    pthread_mutex_unlock(&lock);
    return NULL; 
}

void *fung2(void *vargp)
{
    pthread_mutex_lock(&lock);
    counter++;

    for(int i = 0; i < 1000; i++)
    {

        printf("%s","-");

    }  //task yang lama

    pthread_mutex_unlock(&lock);
    return NULL;
}
 
int main() 
{ 
    pthread_t t1,t2; 

    if(pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("init mutex gagal\n");
        return 1;
    }

    pthread_create(&t1, NULL, fung1, NULL); 
    pthread_create(&t2, NULL, fung2, NULL);

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 

    pthread_mutex_destroy(&lock);
    exit(0); 
}
