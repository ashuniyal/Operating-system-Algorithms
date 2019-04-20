#include<stdio.h>
#include<stdlib.h>

int *pres,*rem;

int getnext(int **ga,int last,int n,int min)
{
int i,flag=0,maxp;
for(i=0;i<n;i++)
{
	if(ga[i][1]<=last && pres[i]==0)
	{
		if(flag==0)
		{
		flag=1;
		maxp=ga[i][6];
		min=i;
		}
		else if(flag==1 && ga[i][6]>maxp)
		{
		maxp=ga[i][6];
		min=i;
		}
	}
}
return min;
}


int check(int n)
{
int i;
for(i=0;i<n;i++)
{
	if(pres[i]==0)
	return 1;
}
return 0;
}
int main()
{
int n,i,j;
int **ga;
int min,last;
float atat=0,awt=0;
printf("\n Enter the number of processes :-  ");
scanf("%d",&n);
ga=(int **)malloc(n*sizeof(int*));
for(i=0;i<n;i++)
ga[i]=(int *)malloc(7*sizeof(int));
pres=(int *)calloc(n,sizeof(int));
rem=(int *)calloc(n,sizeof(int));
for(i=0;i<n;i++)
{
printf("\n Process id :- ");
scanf("%d",&ga[i][0]);
printf("\n Arrival time :- ");
scanf("%d",&ga[i][1]);
printf("\n Burst time :- ");
scanf("%d",&ga[i][2]);
printf("\n Priority :- ");
scanf("%d",&ga[i][6]);
rem[i]=ga[i][2];
if(i==0)
min=i;
else if(ga[i][1]<ga[min][1])
min=i;

ga[i][3]=-1;
ga[i][4]=-1;
ga[i][5]=-1;
}
last=ga[min][1];

while(check(n))
{
rem[min]--;
last++;
if(rem[min]==0)
{
	pres[min]=1;
	ga[min][3]=last;
	ga[min][4]=ga[min][3]-ga[min][1];
	ga[min][5]=ga[min][4]-ga[min][2];
	atat+=ga[min][4];
	awt+=ga[min][5];
}
	min=getnext(ga,last,n,min);

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

