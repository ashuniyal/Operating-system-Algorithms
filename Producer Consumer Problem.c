#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>

sem_t em,fu,cs;
int *block,cc;

void *pro()
{
sem_wait(&em);
sem_wait(&cs);
int i;
block[cc]=1;
cc++;
printf("\n Producer working : ");
for(i=0;i<5;i++)
printf("%d ",block[i]);
sem_post(&cs);
sem_post(&fu);
}

void* con()
{
sem_wait(&fu);
sem_wait(&cs);
int i;
cc--;
block[cc]=0;
printf("\n Consumer working : ");
for(i=0;i<5;i++)
printf("%d ",block[i]);
sem_post(&cs);
sem_post(&em);
}


int main()
{
block=(int *)malloc(5*sizeof(int));
cc=0;
sem_init(&em,0,5);
sem_init(&fu,0,0);
sem_init(&cs,0,1);
pthread_t t1,t2,t3,t4,t5,t6;
pthread_create(&t1,NULL,con,NULL);
pthread_create(&t2,NULL,pro,NULL);
pthread_create(&t3,NULL,con,NULL);
pthread_create(&t4,NULL,pro,NULL);
pthread_create(&t6,NULL,con,NULL);
pthread_create(&t5,NULL,pro,NULL);
pthread_join(t1,NULL);
sleep(2);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);
pthread_join(t5,NULL);
sleep(1);
pthread_join(t6,NULL);
printf("\n");
sem_destroy(&em);
sem_destroy(&fu);
sem_destroy(&cs);
return 0;
}

