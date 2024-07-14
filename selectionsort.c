#include<stdio.h>

void selectionsort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)    
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        
        if(min!=i)
        {
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
        
    }
}

void main()
{
    int arr[]={6,8,2,1,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
