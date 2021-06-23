//Print all the nodes reachable from a given starting node in a digraph using BFS method.
#include<stdio.h>
#include<stdlib.h>
int a[20][20], n, vis[20];
int q[20],front=-1,rear=-1;
int s[20],top=-1;
void bfs(int v)
{
         int i,curr;
         vis[v] = 1;
         q[++rear] = v;
         while(front!=rear){
		   curr = q[++front];
                for(i=1;i<=n;i++){
                        if((a[curr][i]==1)&&(vis[i]==0)){
                                 q[++rear] = i;
                                  vis[i] = 1;
                                  printf("%d ", i);
                        }
               }
        }
}

int main()
{

         int ch, start, i,j;
         printf("\nEnter no. of vertices:  ");
         scanf("%d",&n);
         printf("\nEnter adjacency matrix:\n");
         for(i=1; i<=n; i++){
                for(j=1;j<=n;j++)
                        scanf("%d",&a[i][j]);
          }
    for(i=1;i<=n;i++)
           vis[i]=0;
    printf("\nEnter starting vertex: ");
    scanf("%d",&start);
        printf("\n1.Print all nodes reachable from a given starting node");\
        printf("\n2.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nNodes reachable from starting vertex %d are: ", start);
                    bfs(start);
                    for(i=1;i<=n;i++)
                    {
                        if(vis[i]==0)
                            printf("\n Vertex that is not reachable is %d" ,i);
                    }
                    break;
           case 2: exit(0);
           default: printf("\nInvalid Choice");
        }
}
