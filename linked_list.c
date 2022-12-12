#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertAtStart(struct node *head, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->next = head;
    return newNode;
}

struct node *insertAtEnd(struct node *head, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;

    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    newNode->next = NULL;
    ptr->next = newNode;
    return head;
}

void display(struct node *p)
{

    while ((p != NULL))
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{

    struct node *head = NULL;

    while (1)
    {
        printf("\nChoice 1: Insert at start\nChoice 2: Insert at end\nChoice 3: Display\nChoice 4: Exit\n");
        int choice;
        scanf("%d", &choice);

        int value;
        switch (choice)
        {
        case 1:
            printf("Enter a value to insert at start: ");
            scanf("%d", &value);
            head = insertAtStart(head, value);
            break;
        case 2:
            printf("Enter a value to insert at end: ");
            scanf("%d", &value);
            head = insertAtEnd(head, value);
            break;
        case 3:
            printf("The elements are: ");
            display(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}
