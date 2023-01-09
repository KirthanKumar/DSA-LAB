struct Node
{
    char data;
    struct Node *next;
};

void reverse(struct Node **);
bool compareLists(struct Node *, struct Node *);

bool isPalindrome(struct Node *head)
{
    struct Node *p = head, *q = head;
    struct Node *secondHalf, *r = head;
    struct Node *midNode = NULL;

    bool res = true;

    if (head != NULL && head->next != NULL)
    {
        while (q != NULL && q->next != NULL)
        {
            q = q->next->next;
            r = p;
            p = p->next;
        }
        if (q != NULL)
        {
            midNode = p;
            p = p->next;
        }

        secondHalf = p;
        r->next = NULL;

        reverse(&secondHalf);
        res = compareLists(head, secondHalf);
        reverse(&secondHalf);

        if (midNode != NULL)
        {
            r->next = midNode;
            midNode->next = secondHalf;
        }
        else
            r->next = secondHalf;
    }
    return res;
}

void reverse(struct Node **headRef)
{
    struct Node *prev = NULL;
    struct Node *current = *headRef;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

bool compareLists(struct Node *head1, struct Node *head2)
{
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }

    if (temp1 == NULL && temp2 == NULL)
        return 1;

    return 0;
}
