#include<stdio.h>
#include<stdlib.h>

struct node
{
    char coeff,expo;
    struct node *next;
};

struct node *head1=NULL;
struct node *head2=NULL;

void insert(struct node **head,int coeff,int expo)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->expo=expo;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
    }
    else
    {
        struct node *temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        //temp=newnode;
    }
    //printf("INSERTED\n");
}

void add()
{
    struct node *temp1=head1;
    struct node *temp2=head2;
    struct node *result=NULL;
    struct node *temp3=NULL;
    while(temp1!=NULL  && temp2!=NULL)
    {
        struct node *newnode=malloc(sizeof(struct node));
        newnode->next=NULL;
        
        if(temp1->expo==temp2->expo)
        {
            newnode->coeff=temp1->coeff+temp2->coeff;
            newnode->expo=temp1->expo;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->expo>temp2->expo)
        {
            newnode->coeff=temp1->coeff;
            newnode->expo=temp1->expo;
            temp1=temp1->next;
        }
        else
        {
            newnode->coeff=temp2->coeff;
            newnode->expo=temp2->expo;
            temp2=temp2->next;
        }
        
        if(result==NULL)
        {
            result=newnode;
            temp3=result;
        }
        else
        {
            temp3->next=newnode;
            temp3=temp3->next;
        }
        
    }
        
        while(temp1!=NULL)
        {
            struct node *newnode = malloc(sizeof(struct node));
            newnode->coeff = temp1->coeff;
            newnode->expo = temp1->expo;
            newnode->next = NULL;
            temp3->next = newnode;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
        while(temp2!=NULL)
        {
            struct node *newnode = malloc(sizeof(struct node));
            newnode->coeff = temp2->coeff;
            newnode->expo = temp2->expo;
            newnode->next = NULL;
            temp3->next = newnode;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
        
        struct node *r=result;
        while(r!=NULL)
        {
            printf("%dx^%d",r->coeff,r->expo);
            r=r->next;
            if(r!=NULL)
            {
                printf("+");
            }
        }
}
    


void main()
{
    int t1,t2;
    printf("Enter the power of polynomial-1:");
    scanf("%d", &t1);
    for(int i=0;i<=t1;i++)
    {
        int y1;
        printf("Coefficient of %d:",i);
        scanf("%d", &y1);
        insert(&head1,y1,i);
    }
    
    printf("Enter the power of polynomial-2:");
    scanf("%d", &t2);
    for(int i=0;i<=t2;i++)
    {
        int y2;
        printf("Coefficient of %d:",i);
        scanf("%d", &y2);
        insert(&head2,y2,i);
    }
    
    add();
}

