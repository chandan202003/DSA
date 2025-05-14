#include <stdio.h>
#include <stdlib.h>
int a[10][10],n,indegree[10];
void find_indegree()
{
int i , j, sum;
for(i=0;i<n;i++)
{
sum=0;
for(j=0;j<n;j++)
sum+=a[j][i];
indegree[i]=sum;
}
}
void topology()
{
int u,v,i,t[10],s[10],top=-1,k=0;
find_indegree();
for(i=0;i<n;i++)
{
if(indegree[i]==0) s[++top]=i;
}
while(top!=-1)
{
u=s[top--];
t[k++]=u;
for(v=0;v<n;v++)
{
if(a[u][v]==1)
{
indegree[v]--;
if(indegree[v]==0) s[++top]=v;
}
}
}
printf("The topological order is :\n");
for(i=0;i<n;i++)
printf("-->%d\t",t[i]);
}
void main()
{
int i , j ;
printf("Enter the jobs:");
scanf("%d",&n);
printf("\nEnter the adjacent matrix:\n ");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
}
topology();
}