#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>


sem_t a,b;
int readcount,cc;
char st[50]="We are studying in IIIT KOTA running at Jaipur.";

void *re()
{
int i;
sem_wait(&b);
readcount++;
if(readcount==1)
sem_wait(&a);
sem_post(&b);
printf("\n Reading......\n ");
for(i=0;i<(10+cc);i++)
printf("%c",st[i]);
printf("\n finished.\n");
sleep(4);
sem_wait(&b);
readcount--;
if(readcount==0)
sem_post(&a);
sem_post(&b);
}

void *wr()
{
int i;
sem_wait(&a);
printf("\n Writing.......");
for(i=0;i<10;i++,cc++)
st[cc]='A';
printf("finished. \n");
sem_post(&a);
}


int main()
{
cc=0;
readcount=0;
sem_init(&a,0,1);
sem_init(&b,0,1);
pthread_t t1,t2,t3,t4,t5;
pthread_create(&t1,NULL,re,NULL);
pthread_create(&t2,NULL,wr,NULL);
pthread_create(&t3,NULL,re,NULL);
pthread_create(&t4,NULL,wr,NULL);
pthread_create(&t5,NULL,re,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
sleep(1);
pthread_join(t3,NULL);
pthread_join(t4,NULL);
pthread_join(t5,NULL);
sem_destroy(&a);
sem_destroy(&b);
return 0;
}

