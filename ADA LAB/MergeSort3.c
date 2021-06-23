#include<stdio.h>
 
void mergesort(int arr[],int i,int j);
void sort(int arr[],int a,int b,int a1,int b1);
int main()
{
	int arr[20],n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("Given array without merge sorting: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	mergesort(arr,0,n-1);
	printf("\nMerge sorted array is            : ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
		
	return 0;
}
 
void mergesort(int arr[],int i,int j)
{
	int m;	
	if(i<j)
	{
		m=(i+j)/2;
		mergesort(arr,i,m);		
		mergesort(arr,m+1,j);	
		sort(arr,i,m,m+1,j);
	}
}
 
void sort(int arr[],int a,int b,int a1,int b1)
{
	int temp[20];	
	int i,j,k;
	i=a;	
	j=a1;	
	k=0;
	while(i<=b && j<=b1)
	{
		if(arr[i]<arr[j])
			temp[k++]=arr[i++];
		else
			temp[k++]=arr[j++];
	}
	while(i<=b)	
		temp[k++]=arr[i++];	
	while(j<=b1)	
		temp[k++]=arr[j++];
	for(i=a,j=0;i<=b1;i++,j++)
		arr[i]=temp[j];
}
