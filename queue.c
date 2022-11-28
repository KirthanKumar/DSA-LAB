#include <stdio.h>

#define size 50
int r = -1;
int f = -1;
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
    if (r == size - 1)
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
        printf("Queue overflow\n");
    }
    else
    {
        int element;
        printf("Enter a number to insert into the queue: ");
        scanf("%d", &element);
        r++;
        queue[r] = element;
    }
}

int deQueue()
{
    if (isEmpty())
    {
        printf("Queue underflow\n");
    }
    else
    {
        f++;
        int value = queue[f];
        return value;
    }
}

void queueTraversal()
{
    if (isEmpty())
    {
        printf("Cannot be traversed as queue is empty\n");
    }
    for (int i = f + 1; i <= r; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{

    while (1)
    {
        printf("choice 1 : Enqueue\n");
        printf("choice 2 : Dequeue\n");
        printf("choice 3 : Traversal\n");
        printf("choice 4 : Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enQueue();
            break;

        case 2:
            printf("Deleted element %d from the queue \n", deQueue());
            break;

        case 3:
            queueTraversal();
            break;

        case 4:
            exit(0);

        default:
            printf("Select other choice\n");
        }
    }

    return 0;
}
