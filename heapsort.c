#include<stdio.h>

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void maxheapify(int arr[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    
    if(arr[l]>arr[largest] && l<n)
    {
        largest=l;
    }
    if(arr[r]>arr[largest] && r<n)
    {
        largest=r;
    }
    
    if(largest!=i)
    {
        swap(arr,largest,i);
        maxheapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        maxheapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        swap(arr,0,i);
        maxheapify(arr,i,0);
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
    printf("\n");
    
    heapsort(arr,n);
    
     for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
