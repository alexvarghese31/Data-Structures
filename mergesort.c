#include<stdio.h>

void merge(int arr[],int l,int m,int h)
{
    int n1=m-l+1;
    int n2=h-m;
    int larr[n1];
    int rarr[n2];
    
    for(int i=0;i<n1;i++)
    {
        larr[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        rarr[j]=arr[m+1+j];
    }
    
    int i=0;
    int j=0;
    int k=l;
    
    while(i<n1 && j<n2)
    {
        if(larr[i]<=rarr[j])
        {
            arr[k]=larr[i];
            i++;
        }
        else
        {
            arr[k]=rarr[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        arr[k]=larr[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        arr[k]=rarr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[],int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}

void main()
{
    int arr[]={5,4,9,8,7,3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=0;
    int h=n-1;
    mergesort(arr,l,h);
    
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    
}
