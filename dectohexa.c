#include<stdio.h>

void decTOhexa(int num)
{
    char hexa[100];
    int i=0;
    
    if(num==0)
    {
        printf("hexadecimal equivalent=0");
    }
    
    while(num!=0)
    {
        int rem=num%16;
        if(rem<10)
        {
            hexa[i]=rem+'0';
        }
        else
        {
             hexa[i]=rem+'A'-10;
        }
        i++;
        num=num/16;
    }
    
    printf("The hexadecimal no is:");
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",hexa[j]);
    }
}

void main()
{
    int num;
    printf("Enter the number:");
    scanf("%d",&num);
    decTOhexa(num);
}

