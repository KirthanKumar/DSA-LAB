// Infix to postfix conversion by using stack(using array)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stackk
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stackk *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stackk *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stackk *ptr, char exp)
{
    if (isFull(ptr))
    {
        printf("Stack overflow, cannot push %d to the stack \n", exp);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = exp;
    }
}

char pop(struct stackk *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow\n");
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

char stackTop(struct stackk *s)
{
    return s->arr[s->top];
}
int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char *infixToPostfix(char *infix)
{
    // stack implmentation
    struct stackk *sp = (struct stackk *)malloc(sizeof(struct stackk));
    sp->top = -1;
    sp->size = 50;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0; // i for scanning infix and j is for forming postfix
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++, j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{

    char infix[15];
    printf("Enter the infix expression: ");
    scanf("%s ", infix);
    printf("The postfix of %s is %s ", infix, infixToPostfix(infix));
    return 0;
}