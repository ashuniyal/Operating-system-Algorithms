#include<stdio.h>
#include<stdlib.h>

int rt(int *rem,int *tot,int **ga,int n,int mini)
{
int flag1=0,flag2=0,min=-1,i;
for(i=0;i<n;i++)
{
	if(rem[i]!=0)
	 {flag1=1;}
}
if(flag1==0)
{
	 return -1;
}
if(flag1==1)
{
	for(i=0;i<n;i++)
	{
		if(rem[i]!=0 && ga[i][1]<=(*tot))
		{
			if(min==-1)
			{
				flag2=1;
				min=i;
			}
			else if(rem[i]<rem[min])
			{
				min=i;
			}
		}
	}
	if(rem[min]==rem[mini])
		min=mini;
}

if(flag2==0)
{
min=-1;
for(i=0;i<n;i++)	
	{
		if(ga[i][1]>(*tot) && rem[i]!=0)
		{
			if(min==-1)
			{
				min=i;
				(*tot)=ga[i][1];
			}
			else if(ga[i][1]<ga[min][1])
			{
				min=i;
				(*tot)=ga[i][1];
			}
		}
	}
	if(rem[min]==rem[mini])
		min=mini;

}
return min;
}


int main()
{
int n,i,j;
int **ga;
int *rem;
float atat=0,awt=0;
printf("\n Enter the number of processes :-  ");
scanf("%d",&n);
ga=(int **)malloc(n*sizeof(int*));
rem=(int *)malloc(n*sizeof(int));
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
int tot=ga[min][1];
while(1)
{
rem[min]--;
tot++;

if(rem[min]==0)
{
 ga[min][3]=tot;
 ga[min][4]=ga[min][3]-ga[min][1];
 ga[min][5]=ga[min][4]-ga[min][2];
 atat+=ga[min][4];
 awt+=ga[min][5];
}
min=rt(rem,&tot,ga,n,min);
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

