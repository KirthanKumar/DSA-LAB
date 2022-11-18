// Stack implementation using array along with push(), pop(), isEmpty(), isFull() operations
#include <stdio.h>
#include <stdlib.h>

#define Size 4

int Top = -1;
int array[Size];

int isEmpty()
{
    if (Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    if (Top == Size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Pop()
{
    if (isEmpty())
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int value = array[Top];
        printf("Popped element is:  %d\n", value);
        Top--;
        return value;
    }
}

void Push()
{
    int data;

    if (isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("\nEnter element to be pushed into the stack:");
        scanf("%d", &data);
        Top++;
        array[Top] = data;
    }
}

int main()
{
    for (int i = 0; i < Size; i++)
    {
        Push();
    }
    for (int i = 0; i < Size; i++)
    {
        Pop();
    }
    return 0;
}
