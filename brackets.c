#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max_size 100
#include<string.h>
struct stack
{
    int top;
    int arr[max_size];
};

struct stack* create()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    return s;
}

void push(struct stack*s,int item)
{
    if(s->top==max_size-1)
    {
        printf("Overflow");
    }
    s->top++;
    s->arr[s->top]=item;
}

int pop(struct stack *s)
{
    if(s->top==-1)
    {
        printf("Underflow");
    }
    return s->arr[s->top--];
}

int isPair(char opening,char closing)
{
     return (opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']');
}

int isBalanced(char *exp)
{
    int c=strlen(exp);
    struct stack *s=create();
    for(int i=0;exp[i];i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(s,exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(s->top==-1 || !isPair(pop(s),exp[i]))
            {
                return 0;
            }
        }
    }
    int result=s->top==-1;
    return result;
}
void main()
{
    char exp[]="[5*(2+3)]";
    
    if(isBalanced(exp))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}

