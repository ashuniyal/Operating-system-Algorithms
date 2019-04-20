#include<stdio.h>
#include<stdlib.h>

int n,*b;
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
	int i,max=-10,ind,j;
	for(i=0;i<s;i++)
	{
		if(a[i][0]==-1)
		{
			a[i][0]=in;
			for(j=k+1;j<n;j++)			
			{
				if(b[j]==in)
				{
				a[i][1]=j;
				break;
				}
				if(j==(n-1))
				{
				a[i][1]=n;
				break;
				}
			}
			return;
		}
	}
	for(i=0;i<s;i++)
	{
		if(a[i][1]>max)
		{
			max=a[i][1];
			ind=i;
		}
	}
	a[ind][0]=in;
	for(j=k+1;j<n;j++)			
	{
		if(b[j]==in)
		{
		a[ind][1]=j;
		break;
		}
		if(j==(n-1))
		{
		a[ind][1]=n;
		break;
		}
	}
}

void update(int **a,int s,int in,int k)
{
	int i,j;
	for(i=0;i<s;i++)
	{
		if(a[i][0]==in)
		{
			a[i][1]=k;
			for(j=k+1;j<n;j++)			
			{
				if(b[j]==in)
				{
				a[i][1]=j;
				break;
				}
				if(j==(n-1))
				{
				a[i][1]=n;
				break;
				}
			}
			break;
		}
	}

}

int main()
{
int s;
printf("\nEnter the number of entries in reference string : \n");
scanf("%d",&n);
printf("\nEnter the frame size : ");
scanf("%d",&s);
int **a,i,in,ch;
float r,h=0,m=0;
b=(int *)malloc(n*sizeof(int));
printf("\nEnter reference string :- \n");
for(i=0;i<n;i++)
scanf("%d",&b[i]);
a=(int **)malloc(s*sizeof(int *));
for(i=0;i<s;i++)
{
a[i]=(int *)malloc(2*sizeof(int));
a[i][0]=-1;
a[i][1]=-1;
}
for(i=0;i<n;i++)
{
in=b[i];
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
