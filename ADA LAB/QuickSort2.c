//Q.2 Sort a given set of elements using Quick sort.
#include<stdio.h>
 
void quicksort(int[],int,int);
int sort(int[],int,int);
 
int main()
{
	int arr[50],n,i;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	printf("\nEnter elements in the array: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Array before quick sorting:");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	quicksort(arr,0,n-1);
	printf("\nQuick sorted elements :");
	
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	
	return 0;		
}
 
void quicksort(int arr[],int x,int y)
{
	int m;
	if(x<y)
	{
		m=sort(arr,x,y);
		quicksort(arr,x,m-1);
		quicksort(arr,m+1,y);
	}
}
 
int sort(int arr[],int x,int y)
{
	int v,i,m,temp;
	v=arr[x];
	i=x;
	m=y+1;
	
	do
	{
		do
			i++;	
		while(arr[i]<v&&i<=y);
		do
			m--;
		while(v<arr[m]);
		if(i<m)
		{
			temp=arr[i];
			arr[i]=arr[m];
			arr[m]=temp;
		}
	}while(i<m);
	
	arr[x]=arr[m];
	arr[m]=v;
	
	return(m);
}
