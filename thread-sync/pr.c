#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <time.h>
#include <pthread.h> 
int n, sum, counter, buffer[100];
pthread_mutex_t lock;

void *produce(void *vargp){
    unsigned int seed = time(NULL);
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&lock);
        counter++;
        int rNum = rand_r(&seed) %5;

        buffer[n] = rNum; 
        printf("produced: %d\n", rNum);
        n++;

        pthread_mutex_unlock(&lock);
    }
    
    
}
void *consume(void *vargp){
    
    for(int i = 0; i < 10; i++){
        pthread_mutex_lock(&lock);
        counter++;
        printf("before sum: %d\n",sum);
        n--;
        sum += buffer[n];
        printf("after sum: %d\n",sum);
        
        pthread_mutex_unlock(&lock);
    }

}

int main(){
    int nProducer, nConsumer;
    n = 0;
    sum = 0;

    scanf("%d %d", &nProducer, &nConsumer);

    if(pthread_mutex_init(&lock, NULL) != 0){
        printf("ini mutex gagal");
        return 0;
    }

    pthread_t tProducer[nProducer],tConsumer[nConsumer];

    for(int i = 0; i < 10; i++){
        if(i < nProducer){
            pthread_create(&tProducer[i], NULL, produce, NULL);
            pthread_join(tProducer[i], NULL); 
        }
        
        if(i < nConsumer){
            pthread_create(&tConsumer[i], NULL, consume, NULL);
            pthread_join(tConsumer[i], NULL); 
        }
    }

    pthread_mutex_destroy(&lock);
    return 0;
}