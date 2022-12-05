// WAP to simulate the working of circular queue of integers using an arrray. Provide the following operations. a) Insert, b) Delete, 3) Display. The program should print appropriate messages for queue empty and queue overflow condition.
#include <stdio.h>
#include <stdlib.h>

#define size 50
int f = -1, r = -1;
int queue[size];

int isEmpty()
{
    if (f == r)
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
    if ((r + 1) % size == f || (f == 0 && r == size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue()
{
    if (isFull())
    {
        printf("\nQueue Overflow");
    }
    else
    {
        printf("\nEnter a element to push: ");
        int element;
        scanf("%d", &element);
        r = (r + 1) % size;
        queue[r] = element;
    }
}

int deQueue()
{
    int val = -1;
    if (isEmpty())
    {
        printf("\nQueue Underflow");
    }
    else
    {
        f = (f + 1) % size;
        val = queue[f];
    }
    return val;
}

void traversal()
{
    if (isEmpty())
    {
        printf("\nCannot be traversed as queue is empty ");
    }
    for (int i = f + 1; i <= r; (i++) % size)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{

    while (1)
    {
        printf("Choice 1: Enqueue\nChoice 2: Dequeue\nChoice 3: Traversal\nChoice 4: Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQueue();
            break;

        case 2:
            printf("\nThe element %d is deleted from the queue", deQueue());
            break;

        case 3:
            traversal();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Enter other option\n");
            break;
        }
    }

    return 0;
}