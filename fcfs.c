#include<stdio.h>
#include<stdlib.h>

int main()
{
int n,i,j;
int **ga;
int min,po,tt,last;
float atat=0,awt=0;
printf("\n Enter the number of processes :-  ");
scanf("%d",&n);
ga=(int **)malloc(n*sizeof(int*));
for(i=0;i<n;i++)
ga[i]=(int *)malloc(6*sizeof(int));
for(i=0;i<n;i++)
{
printf("\n Process id :- ");
scanf("%d",&ga[i][0]);
printf("\n Arrival time :- ");
scanf("%d",&ga[i][1]);
printf("\n Burst time :- ");
scanf("%d",&ga[i][2]);
ga[i][3]=-1;
ga[i][4]=-1;
ga[i][5]=-1;
}
last=ga[0][1];
for(i=1;i<n;i++)
{
if(last>ga[i][1])
  last=ga[i][1];
}
for(j=0;j<n;j++)
{
	for(i=0;i<n;i++)
	{
		if(ga[i][3]==-1)
		{
			min=ga[i][1];
			po=i;
			tt=i;
			break;
		}
	}

	for(i=0;i<n;i++)
	{
		if(ga[i][1]<min && ga[i][3]==-1)
		   {
			min=ga[i][1];
			tt=i;
			po=i;
		   }
		else if(ga[i][1]==min && ga[i][3]==-1 && i<tt)
		   {
			min=ga[i][1];
			tt=i;
			po=i;
		   }
	}
	if(ga[po][1]>last)
	 last=ga[po][1];
	ga[po][3]=last+ga[po][2];
	ga[po][4]=ga[po][3]-ga[po][1];
	ga[po][5]=ga[po][4]-ga[po][2];
	last=last+ga[po][2];
	atat+=ga[po][4];
	awt+=ga[po][5];
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

