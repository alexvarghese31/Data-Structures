#include<stdio.h>

void InsertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void main()
{
    int arr[]={5,4,9,8,7,3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    
     for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    
    InsertionSort(arr,n);
    
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
