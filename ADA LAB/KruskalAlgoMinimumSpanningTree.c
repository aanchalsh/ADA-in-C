#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,X=1;
int min,mincost=0,cost[9][9],root[9];
int search(int);
int un(int,int);
int main()
{
	printf("\nEnter  no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("Edges of MST are\n");
	while(X < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=search(u);
		v=search(v);
		if(un(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",X++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
	getch();
	return 0;
}
int search(int i)
{
	while(root[i])
	i=root[i];
	return i;
}
int un(int i,int j)
{
	if(i!=j)
	{
		root[j]=i;
		return 1;
	}
	return 0;
}
