#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
void eval_postfix(char *stack) {
    char ch;
    int i = 0, op1, op2;
    while((ch = stack[i++]) != 0) {
        if(isdigit(ch)) 
            push(ch-'0'); 
        else { 
            op2 = pop();
            op1 = pop();
            switch(ch) {
                case '+' : 
                    push(op1+op2); 
                    break;
                case '-' : 
                    push(op1-op2); 
                    break;
                case '*' : 
                    push(op1*op2);
                    break;
                case '/' : 
                    push(op1/op2);
                    break;
            }
        }
    }
    printf("\n%c\n",stack[top]);
}
int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c ",pop());
    }
    eval_postfix(stack);
    return 0;
}