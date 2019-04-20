#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

sem_t sema;

void *funcc()
{
sem_wait(&sema);
printf("\n Inside critical section. \n");
sleep(100);
sem_post(&sema);
}

int main()
{
pthread_t t1,t2;
sem_init(&sema,0,1);
pthread_create(&t1,NULL,funcc(),NULL);
pthread_create(&t2,NULL,funcc(),NULL);
sem_destroy(&sema);
return 0;
}
