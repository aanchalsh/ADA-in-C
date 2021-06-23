#include<stdio.h>
#define max 20
 
typedef struct edge
{
	int u,v,w;
}edge;
 
typedef struct list
{
	edge data[max];
	int n;
}list;

list e; 
int mat[max][max],n;
list listS;
void minspanTree();
int search_tree(int x1[],int y1no);
void Union(int x1[],int c1,int c2);
void sort();
void display();
 
int main()
{
	int i,j;
	printf("\nEnter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&mat[i][j]);	
	minspanTree();
	display();
	return 0;
}
 
void minspanTree()
{
	int x1[max],i,j,temp1,temp2;
	e.n=0;
	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
		{
			if(mat[i][j]!=0)
			{
				e.data[e.n].u=i;
				e.data[e.n].v=j;
				e.data[e.n].w=mat[i][j];
				e.n++;
			}
		}
	sort();
	for(i=0;i<n;i++)
		x1[i]=i;
	listS.n=0;
	for(i=0;i<e.n;i++)
	{
		temp1=search_tree(x1,e.data[i].u);
		temp2=search_tree(x1,e.data[i].v);
		if(temp1!=temp2)
		{
			listS.data[listS.n]=e.data[i];
			listS.n=listS.n+1;
			Union(x1,temp1,temp2);
		}
	}
}
 
int search_tree(int x1[],int y1)
{
	return(x1[y1]);
}
 
void Union(int x1[],int c1,int c2)
{
	int i;
	
	for(i=0;i<n;i++)
		if(x1[i]==c2)
			x1[i]=c1;
}
 
void sort()
{
	int i,j;
	edge temp;
	for(i=1;i<e.n;i++)
		for(j=0;j<e.n-1;j++)
			if(e.data[j].w>e.data[j+1].w)
			{
				temp=e.data[j];
				e.data[j]=e.data[j+1];
				e.data[j+1]=temp;
			}
}
 
void display()
{
	int i;
	int 
	cost=0;
	for(i=0;i<listS.n;i++)
	{
		printf("\n%d\t%d\t%d",listS.data[i].u,listS.data[i].v,listS.data[i].w);
		cost=cost+listS.data[i].w;
	}
	printf("\nThe cost of the minimum spanning tree=%d",cost);
}
