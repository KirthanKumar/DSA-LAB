#include <stdio.h>

int stack[10];
int top = -1;

int isEmpty(int stack[])
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int stack[], char a)
{

    if (top == 9)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = a;
    }
}

char pop(int stack[])
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        char val = stack[top];
        top--;
        return val;
    }
}

int match(char a, char b)
{

    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }

    return 0;
}

int isValid(char *exp)
{
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stack, exp[i]);
        }

        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(stack))
            {
                return 0;
            }

            popped_ch = pop(stack);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(stack))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}