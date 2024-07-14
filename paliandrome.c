#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};


struct node *head=NULL;
void insert(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
    printf("INSERTED\n");
}

bool paliandrome()
{
    struct node *temp1=head;
    struct node *temp2=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }
    while(temp1!=temp2 && temp1->prev!=temp2)
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        temp1=temp1->next;
        temp2=temp2->prev;
    }
    return true;
}

void main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(5);
    insert(1);
    
    bool r=paliandrome();
    if(r==true)
    {
        printf("\nPaliandrome");
    }
    else
    {
        printf("\nNot Paliandrome");
    }
}
