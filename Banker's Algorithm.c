#include<stdio.h>
#include<stdlib.h>
int *done;

int getrown(int **need,int *ca,int n,int m)
{
int i,j;
for(i=0;i<n;i++)
{
	if(done[i]==1)
	continue;
	int f1=0;
	for(j=0;j<m;j++)
	{
		if(need[i][j]>ca[j])
		{
			f1=1;
			break;
		}
	}
	if(f1==0)
	return i;
}
return -1;
}

int check(int n)
{
int i;
for(i=0;i<n;i++)
{
if(done[i]==0)
return 1;
}
return 0;
}


void addm(int **a,int *b,int pp,int m,int **need,int *ca)
{
int i,j;
for(i=0;i<m;i++)
{
a[pp][i]=a[pp][i]+b[i];
need[pp][i]=need[pp][i]-b[i];
ca[i]=ca[i]-b[i];
}

int flag=0;
for(i=0;i<m;i++)
{
if(need[pp][i]!=0)
flag=1;
}
if(flag==0)
{
printf("\n%d\n",pp);
for(i=0;i<m;i++)
{
ca[i]=ca[i]+a[pp][i];
}
done[pp]=1;
}

}

int main()
{
int i,j,pp,n,m;
int **all,*ins,**max,**need,*req,*ca;
printf("\n Enter the number of process :");
scanf("%d",&n);
printf("\n Enter the number of types of resources :");
scanf("%d",&m);
all=(int**)malloc(n*sizeof(int*));
max=(int**)malloc(n*sizeof(int*));
need=(int**)malloc(n*sizeof(int*));
for(i=0;i<n;i++)
{
all[i]=(int *)malloc(m*sizeof(int));
max[i]=(int *)malloc(m*sizeof(int));
need[i]=(int *)malloc(m*sizeof(int));
}
ins=(int *)malloc(m*sizeof(int));
req=(int *)malloc(m*sizeof(int));
ca=(int *)malloc(m*sizeof(int));
done=(int *)calloc(n,sizeof(int));

printf("\n Enter the allocation matrix : \n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
scanf("%d",&all[i][j]);
}

printf("\n Enter the maximum matrix : \n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
scanf("%d",&max[i][j]);
}

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
need[i][j]=max[i][j]-all[i][j];
}

printf("\n Enter the total instace available :  \n");
for(i=0;i<m;i++)
{
scanf("%d",&ins[i]);
}

printf("\n Enter process for which request is given : \n");
scanf("%d",&pp);

printf("\n Enter the request :  \n");
for(i=0;i<m;i++)
{
scanf("%d",&req[i]);
}


for(i=0;i<m;i++)
{
int s=0;
for(j=0;j<n;j++)
s=s+all[j][i];
ca[i]=ins[i]-s;
}

int flag=0;
for(i=0;i<m;i++)
{
if(req[i]>need[pp][i] || req[i]>ca[i])
flag=1;
}

if(flag==1)
{
printf("\n Request greater than need. \n");
exit(0);
}
else
{
addm(all,req,pp,m,need,ca);
}
int k;

while(check(n))
{
	
	k=getrown(need,ca,n,m);
	if(k==-1)
		{
			printf("\n Not a safe sequence. \n");
			exit(0);
		}
	addm(all,need[k],k,m,need,ca);
}
int r=check(n);
if(r==0)
printf("\n It is a safe sequence. \n");
return 0;
}
