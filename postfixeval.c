#include <stdio.h>
#include <ctype.h>
#include<string.h>
#define MAXSTACK 100 
#define POSTFIXSIZE 100 

/* declare stack and its top pointer to be used during postfix expression
evaluation*/
int stack[MAXSTACK];
int top = -1; 
/* define push operation */
void push(int item)
{

    if (top >= MAXSTACK - 1) {
        printf("stack over flow");
        return;
    }
    else {
        top = top + 1;
        stack[top] = item;
    }
}

/* define pop operation */
int pop()
{
    int item;
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

/* define function that is used to input postfix expression and to evaluate it */
void EvalPostfix(char postfix[])
{

    int i;
    char ch;
    int val;
    int A, B;

    /* evaluate postfix expression */
    for (i = 0; i<strlen(postfix); i++) {
        ch = postfix[i];
        if (ch>='0' && ch<='9'){
            /* we saw an operand,push the digit onto stack
ch - '0' is used for getting digit rather than ASCII code of digit */
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            /* we saw an operator
* pop top element A and next-to-top elemnet B
* from stack and compute B operator A
*/
            A = pop();
            B = pop();

            switch (ch) /* ch is an operator */
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            default:
                printf("Invalid operator\n");
                //exit(1);
            }

            /* push the value obtained above onto the stack */
            push(val);
        }
    }
    printf(" \n Result of expression evaluation : %d \n", pop());
}

void main()
{
    char str[]="568+-726*-+";
    EvalPostfix(str);
}
