#include<stdio.h>
#include<stdlib.h>

int main()
{
int n,i,j;
int **ga;
int po,tt,last;
float atat=0,awt=0,*extr,min,alpha;
printf("\n Enter the number of processes :-  ");
scanf("%d",&n);
ga=(int **)malloc(n*sizeof(int*));
for(i=0;i<n;i++)
ga[i]=(int *)malloc(6*sizeof(int));
extr=(float *)malloc(n*sizeof(float));
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
printf("\nEnter alpha :- ");
scanf("%f",&alpha);
printf("\nEnter T1 :- ");
scanf("%f",&extr[0]);
for(i=1;i<n;i++)
{
extr[i]=alpha*ga[i-1][2]+(1-alpha)*extr[i-1];
}
/*float sel;
last=ga[0][1];
sel=extr[0];
int k;
for(i=1;i<n;i++)
{
if(last>ga[i][1])
  {
   last=ga[i][1];
   k=i;
   sel=extr[i];
  }
else if(last==ga[i][1] && sel>extr[i])
  {
   last=ga[i][1];
   k=i;
   sel=extr[i];
  }
}
ga[k][3]=last+ga[k][2];
ga[k][4]=ga[k][3]-ga[k][1];
ga[k][5]=ga[k][4]-ga[k][2];
last=last+ga[k][2];
atat+=ga[k][4];
awt+=ga[k][5];

for(j=1;j<n;j++)
{
	for(i=0;i<n;i++)
	{
		if(ga[i][3]==-1)
		{
			min=extr[i];
			po=i;
			tt=ga[i][1];
			break;
		}
	}

	for(i=0;i<n;i++)
	{
		if(extr[i]<min && ga[i][3]==-1 && ga[i][1]<=last)
		   {
			min=extr[i];
			tt=ga[i][1];
			po=i;
		   }
		else if(extr[i]==min && ga[i][3]==-1 && ga[i][1]<tt)
		   {
			min=extr[i];
			tt=ga[i][1];
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
}*/
for(i=0;i<n;i++)
printf("\n %f",extr[i]);
/*printf("\nAverage turn around time is :- %f",atat);
printf("\nAverage waiting time is :- %f \n",awt);
*/
return 0;
}

