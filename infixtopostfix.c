#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int precedence(char i)
{
    if(i=='^')
    {
        return 3;
    }
    else if(i=='*' || i=='/')
    {
        return 2;
    }
    else if(i=='+' || i=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void postfix(char str[])
{
    char s[100];
    int top=-1;
    char r[100];
    int rindex=0;
    int n=strlen(str);
    
    for(int i=0;i<n;i++)
    {
        char c=str[i];
        
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        {
            r[rindex]=c;
            rindex++;
        }
        else if(c=='(')
        {
            top++;
            s[top]=c;
        }
        else if(c==')')
        {
            while(s[top]!='(' && top>=0)
            {
                r[rindex]=s[top];
                rindex++;
                top--;
            }
            top--;
        }
        else
        {
            while(top>=0 && (precedence(c)<=precedence(s[top])))
            {
                r[rindex]=s[top];
                top--;
                rindex++;
            }
            top++;
            s[top]=c;
            
        }
    }
    while(top>=0)
    {
        r[rindex]=s[top];
        top--;
        rindex++;
    }
    r[rindex]='\0';
    printf("%s\n",r);
}

void main()
{
    char str[]="(a+b)*(c+d)";
    postfix(str);
}
