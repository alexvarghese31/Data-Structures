#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int key)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=NULL;
    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    printf("INSERTED\n");
}

void dequeue()
{
    if(front==NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        struct node*temp=front;
        int x=temp->data;
        printf("Deleted data is%d:",x);
        front=temp->next;
        free(temp);
    }
}

void display()
{
    if(front==NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
        struct node *temp=front;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        
        if(ch==1)
        {
            int n;
             printf("Enter the integer:\n");
            scanf("%d", &n);
            enqueue(n);
        }
        else if(ch==2)
        {
            dequeue();
        }
        else if(ch==3)
        {
            display();
        }
        else if(ch==4)
        {
            exit(0);
        }
        else
        {
            printf("Invalid Output\n");
        }
    }
}
