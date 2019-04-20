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

void replace(int **a,int s,int in)
{
int i,max=-2,ind;
for(i=0;i<s;i++)
{
if(a[i][0]==-1)
{
a[i][0]=in;
a[i][1]=0;
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
a[ind][1]=0;
}

void incre(int **a,int s)
{
int i;
for(i=0;i<s;i++)
{
if(a[i][0]!=-1)
a[i][1]++;
}
}

int main()
{
int n,s;
printf("\nEnter the number of entries in reference string : \n");
scanf("%d",&n);
printf("\nEnter the frame size : ");
scanf("%d",&s);
int **a,in,i;
float r,h=0,m=0;
a=(int **)malloc(s*sizeof(int *));
for(i=0;i<n;i++)
{
a[i]=(int *)malloc(2*sizeof(int));
a[i][0]=-1;
a[i][1]=0;
}
for(i=0;i<n;i++)
{
int ch;
printf("\nEnter the page number : \n");
scanf("%d",&in);
incre(a,s);
ch=checkin(a,s,in);
if(ch==1)
h++;
else
{
m++;
replace(a,s,in);
}
}
r=(float)((h/(h+m))*100);
printf("\nHit ratio : %f\n",r);
r=(float)(100-r);
printf("\nMiss ratio : %f\n",r);
return 0;
}
