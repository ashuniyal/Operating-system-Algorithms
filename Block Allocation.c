#include<stdio.h>
#include<stdlib.h>

void ffit(int n,int **par,int m,int **req)
{
int i,j;
for(i=0;i<m;i++)
{
	for(j=0;j<n;j++)
	{
		if(par[j][2]>req[i][0])
		{
			req[i][1]=j;
			par[j][2]=par[j][2]-req[i][0];
			break;
		}
	}
}

for(i=0;i<m;i++)
{
if(req[i][1]!=-1)
printf("\n %d -> %d \n",req[i][0],par[req[i][1]][0]);
}

for(i=0;i<n;i++)
{
par[i][2]=par[i][0];
}

for(i=0;i<m;i++)
{
req[i][1]=-1;
}

}

void bfit(int n,int **par,int m,int **req)
{
int i,j;
for(i=0;i<m;i++)
{
	int min=9999,k=-1;
	for(j=0;j<n;j++)
	{
		if(par[j][0]>=req[i][0] && par[j][1]==-1 && (par[j][0]-req[i][0])<min)
		{
			min=par[j][0]-req[i][0];
			k=j;
		}
	}
	if(k!=-1)
	{
		par[k][1]=1;
		req[i][1]=k;
	}
}

for(i=0;i<m;i++)
{
if(req[i][1]!=-1)
printf("\n %d -> %d \n",req[i][0],par[req[i][1]][0]);
}

for(i=0;i<n;i++)
{
par[i][1]=-1;
}

for(i=0;i<m;i++)
{
req[i][1]=-1;
}


}

void nfit(int n,int **par,int m,int **req)
{
int i,j,c=-1,flag;
for(i=0;i<m;i++)
{
	flag=0;
	for(j=c+1;j<n;j++)
	{
		if(par[j][2]>req[i][0])
		{
			req[i][1]=j;
			par[j][2]=par[j][2]-req[i][0];
			c=j;
			flag=1;
			break;
		}
	}
	for(j=0;j<=c && flag==0;j++)
	{
		if(par[j][2]>req[i][0])
		{
			req[i][1]=j;
			par[j][2]=par[j][2]-req[i][0];
			c=j;
			break;
		}
	}
}

for(i=0;i<m;i++)
{
if(req[i][1]!=-1)
printf("\n %d -> %d \n",req[i][0],par[req[i][1]][0]);
}

for(i=0;i<n;i++)
{
par[i][2]=par[i][0];
}

for(i=0;i<m;i++)
{
req[i][1]=-1;
}


}

int main()
{
int **par,**req,n,m,i;
printf("\n Enter the number of memory partitions :  \n");
scanf("%d",&n);
par=(int **)malloc(n*sizeof(int*));
for(i=0;i<n;i++)
{
par[i]=(int *)malloc(3*sizeof(int));
scanf("%d",&par[i][0]);
par[i][1]=-1;
par[i][2]=par[i][0];
}
printf("\n Enter the number of requests : \n");
scanf("%d",&m);
req=(int **)malloc(m*sizeof(int *));
for(i=0;i<m;i++)
{
req[i]=(int *)malloc(2*sizeof(int));
scanf("%d",&req[i][0]);
req[i][1]=-1;
}
printf("\nFirst fit results :- \n");
ffit(n,par,m,req);
printf("\nBest fit results :- \n");
bfit(n,par,m,req);
printf("\nNext fit results :- \n");
nfit(n,par,m,req);
return 0;
}
