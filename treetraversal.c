#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *l;
    struct node *r;
};

struct node* create(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->l=NULL;
    newnode->r=NULL;
    return newnode;
}

void insertLeft(struct node *root,int value)
{
    root->l=create(value);
    printf("INSERTED ON THE LEFT\n");
}

void insertRight(struct node *root,int value)
{
    root->r=create(value);
    printf("INSERTED ON THE RIGHT\n");
}

void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->l);
    printf("%d ",root->data);
    inorder(root->r);
}

void preorder(struct node *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preorder(root->l);
    preorder(root->r);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->l);
    postorder(root->r);
    printf("%d ",root->data);
}

int main()
{
    struct node *root=create(50);
    insertLeft(root,40);
    insertRight(root,30);
    insertLeft(root->l,20);
    insertRight(root->r,60);
    
    printf("INORDER\n");
    inorder(root);
    printf("\nPREORDER\n");
    preorder(root);
    printf("\nPOSTORDER\n");
    postorder(root);
    
    return 0;
}
