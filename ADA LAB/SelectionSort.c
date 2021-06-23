#include<stdio.h>
 
int main()
{
    int i,j,n,pos,temp,m,arr[30];
    printf("Enter the no. of elements:");
    scanf("%d",&n);
    printf("\nEnter the array elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Array elements before selection sort: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    for(i=0;i<n-1;i++)
    {
        m=arr[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(m>arr[j])
            {
                m=arr[j];
                pos=j;
            }
        }
 
        temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }
 
    printf("\nSelection sorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
 
    return 0;
}
