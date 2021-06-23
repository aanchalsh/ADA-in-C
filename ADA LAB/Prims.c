#include<stdio.h>
#include<stdlib.h>
#define last 9999
#define MAX 20
 
int G[MAX][MAX],span[MAX][MAX],n;
int PrimsAlgo();
int main()
{
int i,j,total;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	total=PrimsAlgo();
	printf("\nSpanning tree matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
			printf("%d\t",span[i][j]);
}
printf("\n\nTotal cost of spanning tree :%d",total);
return 0;
}
 
int PrimsAlgo()
{
	int cost[MAX][MAX];
	int u,v,min,dist[MAX],from[MAX];
	int vis[MAX],no_of_edges,i,min_cost,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
		if(G[i][j]==0)
			cost[i][j]=last;
		else
			cost[i][j]=G[i][j];
		span[i][j]=0;
}
	dist[0]=0;
	vis[0]=1;
	for(i=1;i<n;i++)
	{
		dist[i]=cost[0][i];
		from[i]=0;
		vis[i]=0;
	}
	min_cost=0; //cost of spanning tree
	no_of_edges=n-1; //no. of edges to be added
	while(no_of_edges>0)
	{
		min=last;
		for(i=1;i<n;i++)
		if(vis[i]==0&&dist[i]<min)
		{
			v=i;
			min=dist[i];
		}
	u=from[v];
	span[u][v]=dist[v];
	span[v][u]=dist[v];
	no_of_edges--;
	vis[v]=1;
	for(i=1;i<n;i++)
	if(vis[i]==0&&cost[i][v]<dist[i])
	{
		dist[i]=cost[i][v];
		from[i]=v;
	}
	min_cost=min_cost+cost[u][v];
	}
	return(min_cost);
}
