#include <stdio.h>
#include <pthread.h>

int saldo;

void * printHola(void *arg){
    int pid = *((int *)arg);
    printf("Hola desde el hilo. Soy el hilo%d\n", pid);
    pthread_exit(NULL);

}

void * incrementaSaldo(void *arg){
    saldo +=100;
    pthread_exit(NULL);
}


int main(){
    int NUM_THREADS = 20;
    pthread_t hiloStatus[20];
    int pids[NUM_THREADS];
    saldo=0;

    for(int i=0; i<NUM_THREADS;++i){
        pids[i] = i;
        pthread_create(&hiloStatus[i], NULL, incrementaSaldo,(void *)&pids[i]);
    }

    for(int i = 0; i<NUM_THREADS;++i){
        pthread_join(hiloStatus[i],NULL);
    }
    printf("Saldo final: %d\n", saldo);
    pthread_exit(NULL);
}