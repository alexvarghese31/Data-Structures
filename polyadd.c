#include<stdio.h>

void create(int p[],int t)
{
    if(t<0)
    {
        printf("Negative degree not entertained");
    }
    
    for(int i=0;i<=t;i++)
    {
        printf("Enter the coefficient of x^%d: ",i);
        scanf("%d", &p[i]);
    }
    
    for(int i=t;i>=0;i--)
    {
        if(p[i]!=0)
        {
            printf("%dx^%d",p[i], i);
            printf("\n");
        }
    }
}

void main()
{
    int t1,t2,p1[100]={0},p2[100]={0},t3,p3[100]={0};
    printf("Enter the degree of polynomial 1:");
    scanf("%d", &t1);
    create(p1,t1);
    
    printf("Enter the degree of polynomial 2:");
    scanf("%d", &t2);
    create(p2,t2);
    
    if(t1>t2)
    {
        t3=t1;
    }
    else if(t2>t1)
    {
        t3=t2;
    }
    else
    {
        t3=t1;
    }
    
    for(int i=t3;i>=0;i--)
    {
        p3[i]=p1[i]+p2[i];
    }
    
    for(int i=t3;i>=0;i--)
    {
        if(p3[i]!=0)
        {
            printf("%dx^%d",p3[i], i);
        }
    }
}
