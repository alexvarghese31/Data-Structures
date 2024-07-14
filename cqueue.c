#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define maxsize 50

int arr[maxsize],f=-1,r=-1;

void enqueue(int data)
{
    if((r+1)%maxsize==f)
    {
        printf("FULL");
    }
    else if(r==-1 && f==-1)
    {
        f=0;
        r=0;
        arr[r]=data;
    }
    else
    {
        r=(r+1)%maxsize;
        arr[r]=data;
    }
}

void dequeue()
{
    if(r==-1)
    {
        printf("EMPTY");
    }
    else if(f==r)
    {
        f=r=-1;
    }
    else
    {
        int x=arr[f];
        printf("%d",x);
        f=(f+1)%maxsize;
    }
}

void peek()
{
    if(r==-1)
    {
        printf("EMPTY");
    }
    else
    {
        int x=arr[f];
        printf("%d",x);
    }
}

void display()
{
    if(r==-1)
    {
        printf("EMPTY");
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
}

void main()
{
    int ch,n;
    while(true)
    {
    printf("1.ENQUEUE\n2.DEQUEUE\n3.Peek\n4.Display\n5.Exit");
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    
    switch(ch)
    {
        case 1:
            printf("Enter your integer:");
            scanf("%d", &n);
            enqueue(n);
            break;
        
        case 2:
            dequeue();
            break;
            
        case 3:
            peek();
            break;
            
        case 4:
            display();
            break;
            
        case 5:
            exit(0);
            break;
            
        default:
            printf("INVALID");
    }
}
}
