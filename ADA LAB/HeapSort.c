#include <stdio.h>
int main()
{
    int heap[100], n,i,j,c,head,temp;
    printf("\n Enter no. of elements :");
    scanf("%d", &n);
    printf("\n Enter the numbers : ");
    for (i = 0; i < n; i++)
       scanf("%d", &heap[i]);
    for (i = 1; i < n; i++)
    {
        c=i;
        do{
            head =(c-1)/2;             
            if (heap[head]<heap[c]) 
            {
                temp=heap[head];
                heap[head]=heap[c];
                heap[c]=temp;
            }
            c = head;
        } while (c != 0);
    }
 
    printf("Heap array : ");
    for (i = 0; i < n; i++)
        printf("%d\t", heap[i]);
    for (j = n - 1; j >= 0; j--)
    {
        temp = heap[0];
        heap[0] = heap[j]; 
        heap[j] = temp;
        head = 0;
        do 
        {
            c = 2*head + 1;   
            if ((heap[c] < heap[c + 1]) && c < j-1)
                c++;
            if (heap[head]<heap[c] && c<j)    
            {
                temp = heap[head];
                heap[head] = heap[c];
                heap[c] = temp;
            }
            head = c;
        } while (c < j);
    } 
    printf("\nSorted array is : ");
    for (i=0;i<n;i++)
       printf("\t %d", heap[i]);
    return 0;
}
