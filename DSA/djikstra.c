#include <stdio.h>
#include <stdlib.h>
int cost[10][10],dist[10],s;
// function implenting dijkstra’s algorithm
dijkstra(int n)
{
int count=1,u,i,v,flag[10],min;
for(i=1;i<=n;i++)
{
flag[i]=0;
dist[i]=999;
}
dist[s]=0;
while(count<=n)
{
min=99;
for(v=1;v<=n;v++)
if(dist[v]<min && !flag[v])
min=dist[v],u=v;
flag[u]=1;
count++;
for(v=1;v<=n;v++)
if((dist[u]+cost[u][v]< dist[v])&& !flag[v])
dist[v]=dist[u]+cost[u][v];
}
}
int main()
{
int i,j,n;
printf("Enter the vertices:");
scanf("%d",&n);
printf("\n enter the cost matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0) cost[i][j]=999;
}
printf("\n enter the source vertex:");
scanf("%d",&s);
dijkstra(n);
printf("\n the shortest path \n");
for(i=1;i<=n;i++)
{
if(i!=s)
printf(" %d -> %d , cost =%d\n",s,i,dist[i]);
}
return 0;
}