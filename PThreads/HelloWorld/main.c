#include <pthread.h>
#include <stdio.h>
#include <string.h>

void* WorkerFunction(void*);

int main(void)
{
    int rank1 = 1;
    int rank2 = 2;

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, *WorkerFunction, (void*)rank1);
    pthread_create(&thread2, NULL, *WorkerFunction, (void*)rank2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}

void *WorkerFunction(void *arg)
{
  printf("Hello, World from thread %d!\n", arg); 
  return 0;
}