#include<stdio.h>

void decTObin(int num)
{
    char bin[100];
    int i=0;
    
    if(num==0)
    {
        printf("binary equivalent=%d", 0);
    }
    
    while(num!=0)
    {
        int rem=num%2;
        bin[i]=rem+'0';
        i++;
        num=num/2;
    }
        
    
    printf("The binary no is:");
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",bin[j]);
    }
}

void main()
{
    int num;
    printf("Enter the number:");
    scanf("%d",&num);
    decTObin(num);
}

