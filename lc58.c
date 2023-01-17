#include<stdio.h>
int top = -1;
int arr[100];
void push(char x)
{
    top++;
    arr[top] = x;
    
}

char pop()
{
    if(top == -1)
    {
        return -1;
    }
    else{
        top--;
        return arr[top+1];
    }
}

int precedence(char x)
{
    if(x == '(')
    {
        return 1;
    }
    else if(x == '+' || x == '-')
    {
        return 2;
    }
    else if(x == '/'|| x == '*')
    {
        return 3;
    }
    else if(x == '^')
    {
        return 4;
    }
    else 
        return 0;
}

int opt(char x)
{
    if (x == '-'||x == '+'|| x == '-' || x == '*' || x == '/'|| x == '(' || x == ')'|| x=='^')
    {
        return 1;
    }
    
}

int main()
{
    char infix[100] = "a+b*c+d/e^f*g-h";
    char *e;
    // printf("%s",infix);
    e = infix;
    while (*e != '\0')
    {
        if (opt(*e) != 1)
        {
            printf("%c",*e);
        }
        else if(*e == '(')
        {
            push(*e);
        }
        else if(*e == ')')
        {
            while (pop() != '(')
            {
                printf("%c",*e);
            }
            
        }
        else
        {
            while(precedence(arr[top]) >= precedence(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        printf("%c",pop());
    }
    
    
    return 0;
}