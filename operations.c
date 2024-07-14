#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
void create(int key)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=key;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    printf("INSERTED\n");
}

void sum()
{
    int sum=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        sum=sum+temp->data;
        temp=temp->next;
    }
    printf("SUM=%d\n",sum);
}

void maxmin()
{
    struct node *temp=head;
    int max=temp->data;
    int min=temp->data;
    while(temp!=NULL)
    {
        if(temp->data>max)
        {
            max=temp->data;
        }
        temp=temp->next;
    }
    printf("MAX=%d\n",max);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data<min)
        {
            min=temp->data;
        }
        temp=temp->next;
    }
    printf("MIN=%d\n",min);
}

void duplicate()
{
    struct node *temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            struct node *dup=temp->next;
            temp->next=temp->next->next;
            free(dup);
        }
        else
        {
            temp=temp->next;
        }
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}

void copy()
{
    struct node *temp=head;
    struct node *copy=NULL;
    while(temp!=NULL)
    {
        struct node *newnode=malloc(sizeof(struct node));
        newnode->data=temp->data;
        newnode->next=NULL;
        if(copy==NULL)
        {
            copy=newnode;
        }
        else
        {
            newnode->next=copy;
            copy=newnode;
        }
        temp=temp->next;
    }
    
    temp=copy;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}

void main()
{
    int ch;
    while(1)
    {
        printf("0.Create\n1.Sum\n2.Max/Min\n3.Delete Duplicates\n4.Copy\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        
        if(ch==0)
        {
            int n;
            printf("Enter the integer:\n");
            scanf("%d", &n);
            create(n);
        }
        else if(ch==1)
        {
            sum();
        }
        else if(ch==2)
        {
            maxmin();
        }
        else if(ch==3)
        {
            duplicate();
        }
        else if(ch==4)
        {
            copy();
        }
        else if(ch==5)
        {
            exit(0);
        }
        else
        {
            printf("Invalid Output\n");
        }
    }
}
