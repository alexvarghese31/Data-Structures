#include<stdio.h>

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int l,int h)
{
    int pivot=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,h);
    return i+1;
}

void quicksort(int arr[],int l,int h)
{
    if(l<h)
    {
        int pivot=partition(arr,l,h);
        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,h);   
    }
}

void main()
{
    int arr[]={5,4,9,8,7,3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=0;
    int h=n-1;
    quicksort(arr,l,h);
    
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
