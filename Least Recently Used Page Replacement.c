#include<stdio.h>
#include<stdlib.h>

int checkin(int **a,int s,int in)
{
int i;
for(i=0;i<s;i++)
{
if(a[i][0]==in)
return 1;
}
return 0;
}

void replace(int **a,int s,int in,int k)
{
	int i,min=999,ind;
	for(i=0;i<s;i++)
	{
		if(a[i][0]==-1)
		{
			a[i][0]=in;
			a[i][1]=k;
			return;
		}
	}
	for(i=0;i<s;i++)
	{
		if(a[i][1]<min)
		{
			min=a[i][1];
			ind=i;
		}
	}
	a[ind][0]=in;
	a[ind][1]=k;
}

void update(int **a,int s,int in,int k)
{
	int i;
	for(i=0;i<s;i++)
	{
		if(a[i][0]==in)
		{
			a[i][1]=k;
			break;
		}
	}

}

int main()
{
int n,s;
printf("\nEnter the number of entries in reference string : \n");
scanf("%d",&n);
printf("\nEnter the frame size : ");
scanf("%d",&s);
int **a,i,in,ch;
float r,h=0,m=0;
a=(int **)malloc(s*sizeof(int *));
for(i=0;i<s;i++)
{
a[i]=(int *)malloc(2*sizeof(int));
a[i][0]=-1;
a[i][1]=-1;
}
printf("\nEnter reference string :- \n");
for(i=0;i<n;i++)
{
scanf("%d",&in);
ch=checkin(a,s,in);
if(ch==1)
{
h++;
update(a,s,in,i);
}
else
{
m++;
replace(a,s,in,i);
}
}
r=(float)((h/(h+m))*100);
printf("\nHit ratio : %f\n",r);
r=(float)(100-r);
printf("\nMiss ratio : %f\n",r);
return 0;
}
