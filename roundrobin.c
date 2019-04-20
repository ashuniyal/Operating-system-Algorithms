#include<stdio.h>
#include<stdlib.h>

struct queue{
int *ele;
int front;
int rear;
};

struct queue createqueue(int n)
{
struct queue q;
q.ele=(int *)malloc(5*n*sizeof(int));
q.front=0;
q.rear=0;
return q;
}

int *pres;

void enqueue(struct queue *q,int *tot,int **ga,int n,int *rem,int min)
{
int k,i,j,l;
k=q->rear;

for(i=0;i<n;i++)
{
if(ga[i][1]>=ga[min][1] && ga[i][1]<=(*tot) && i!=min && rem[i]!=0 && pres[i]==0)
{
q->ele[q->rear]=i;
q->rear=(q->rear)+1;
pres[i]=1;
}
}

l=(q->rear)-1;

for(i=k;i<l;i++)
{
for(j=k;j<l;j++)
{
if(ga[q->ele[j]][1]>ga[q->ele[j+1]][1])
{
int temp=q->ele[j];
q->ele[j]=q->ele[j+1];
q->ele[j+1]=temp;
}
}
}

if(rem[min]!=0)
{
q->ele[q->rear]=min;
q->rear=(q->rear)+1;
}

}

int delq(struct queue *q,int *rem,int n)
{
int i,f=0;
for(i=0;i<n;i++)
{
if(rem[i]!=0)
f=1;
}
if(f==0)
return -1;

if(q->front==q->rear && q->front!=0)
{
return -1;
}
else
{
int ret=q->ele[q->front];
q->front=q->front+1;
return ret;
}

}


int main()
{
int n,i,j,timeq;
int **ga;
int *rem;
struct queue q;
float atat=0,awt=0;
printf("\n Enter the number of processes :-  ");
scanf("%d",&n);
q=createqueue(n);
ga=(int **)malloc(n*sizeof(int*));
rem=(int *)malloc(n*sizeof(int));
pres=(int *)calloc(n,sizeof(int));
for(i=0;i<n;i++)
ga[i]=(int *)malloc(6*sizeof(int));
int min;
for(i=0;i<n;i++)
{
printf("\n Process id :- ");
scanf("%d",&ga[i][0]);
printf("\n Arrival time :- ");
scanf("%d",&ga[i][1]);
printf("\n Burst time :- ");
scanf("%d",&ga[i][2]);
rem[i]=ga[i][2];

if(i==0)
 min=i;
else if(ga[i][1]<ga[min][1])
 min=i;

ga[i][3]=-1;
ga[i][4]=-1;
ga[i][5]=-1;
}
printf("\n Enter time quanta :- ");
scanf("%d",&timeq);
int tot=ga[min][1];
pres[min]=1;
while(1)
{
if(rem[min]>=timeq)
{
rem[min]=rem[min]-timeq;
tot=tot+timeq;
}
else if(rem[min]<timeq)
{
tot=tot+rem[min];
rem[min]=0;
}
if(rem[min]==0)
{
 ga[min][3]=tot;
 ga[min][4]=ga[min][3]-ga[min][1];
 ga[min][5]=ga[min][4]-ga[min][2];
 atat+=ga[min][4];
 awt+=ga[min][5];
}
enqueue(&q,&tot,ga,n,rem,min);
min=delq(&q,rem,n);
if(min==-1)
{
 break;
}

}
atat=(float)atat/n;
awt=(float)awt/n;
printf("\nPid AT BT  CT  TAT  WT");
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<6;j++)
printf("%d   ",ga[i][j]);
}
printf("\nAverage turn around time is :- %f",atat);
printf("\nAverage waiting time is :- %f \n",awt);
return 0;
}

