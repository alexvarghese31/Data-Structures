#include<stdio.h>

void main()
{
    int r,c;
    printf("Enter the r: ");
    scanf("%d", &r);
    printf("Enter the c: ");
    scanf("%d", &c);
    
    int a[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Enter the no: ");
            scanf("%d", &a[i][j]);
            
        }
    }
    
    int size=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                size++;
            }
        }
    }
    
    int k=1,b[size+1][3];
    b[0][0]=r;
    b[0][1]=c;
    b[0][2]=size;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d", b[i][j]);
        }
        printf("\n");
    }
    
    int c1[size+1][3];
    c1[0][0]=c;
    c1[0][1]=r;
    c1[0][2]=size;
    k=1;
    for(int i=0;i<c;i++)
    {
        for(int j=1;j<=size;j++)
        {
            if(b[j][1]==i)
            {
                c1[k][0]=b[j][1];
                c1[k][1]=b[j][0];
                c1[k][2]=b[j][2];
                k++;
            }   
        }
    }
    
    for(int i=0;i<=size;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d", c1[i][j]);
        }
        printf("\n");
    }
}
