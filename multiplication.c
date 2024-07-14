#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff, expo;
    struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *result = NULL;

void insert(struct node **head, int coeff, int expo)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->expo = expo;
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void multiply()
{
    struct node *temp1 = head1;
    while (temp1 != NULL)
    {
        struct node *temp2 = head2;
        while (temp2 != NULL)
        {
            struct node *newnode = malloc(sizeof(struct node));
            newnode->coeff = temp1->coeff * temp2->coeff;
            newnode->expo = temp1->expo + temp2->expo;
            newnode->next = NULL;

            if (result == NULL)
            {
                result = newnode;
            }
            else
            {
                struct node *temp3 = result;
                while (temp3->next != NULL)
                {
                    temp3 = temp3->next;
                }
                temp3->next = newnode;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void display(struct node *result)
{
    struct node *r = result;
    while (r != NULL)
    {
        printf("%dx^%d", r->coeff, r->expo);
        r = r->next;
        if (r != NULL)
        {
            printf("+");
        }
    }
}

int main()
{
    int t1, t2;
    printf("Enter the power of polynomial-1:");
    scanf("%d", &t1);
    for (int i = 0; i <= t1; i++)
    {
        int y1;
        printf("Coefficient of %d:", i);
        scanf("%d", &y1);
        insert(&head1, y1, i);
    }
    
    printf("Enter the power of polynomial-2:");
    scanf("%d", &t2);
    for (int i = 0; i <= t2; i++)
    {
        int y2;
        printf("Coefficient of %d:", i);
        scanf("%d", &y2);
        insert(&head2, y2, i);
    }
    
    multiply();
    printf("Result after multiplication: ");
    display(result);
    
    return 0;
}
