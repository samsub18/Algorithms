#include <stdio.h>
#include <stdlib.h>

// Insert a node after a node pointed by x;

struct Node
{
    int data;
    struct Node *link;
};

void createLL(int val, struct Node **main_head)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->link = NULL;
    *main_head = ptr;
}

int len(struct Node *main_head)
{
    int len = 0;
    struct Node *ptr = main_head;

    while (ptr != NULL)
    {
        len += 1;
        ptr = ptr->link;
    }

    return len;
}

void push(int val, struct Node **main_head) // head-->1-->2-->3   101
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;

    if (*main_head == NULL)
    {
        *main_head = ptr;
        ptr->link = NULL;
    }

    else
    {
        ptr->link = *main_head;
        *main_head = ptr;
    }
}

void append(int val, struct Node **main_head)
{
    struct Node *ptr;
    struct Node *last;

    last = *main_head;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->link = NULL;

    if (last == NULL)
    {
        *main_head = ptr;
        return;
    }

    while (last->link != NULL)
    {
        last = last->link;
    }

    last->link = ptr;
}

void display(struct Node *main_head)
{
    struct Node *ptr;
    ptr = main_head;
    while (ptr != NULL)
    {
        printf("%d-->", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void concatenate(struct Node **head_1, struct Node **head_2)
{
    struct Node *last_1 = *head_1; // A pointer which points to the last element of the first linked list

    while (last_1->link != NULL)
    {
        last_1 = last_1->link;
    }

    last_1->link = *head_2;
}

void reverse(struct Node **main_head)
{
    struct Node *prev = NULL;
    struct Node *next = NULL;
    struct Node *cur = *main_head;

    while (cur != NULL)
    {
        next = cur->link;

        cur->link = prev; // Actual reversing takes place.

        prev = cur;

        cur = next;
    }

    *main_head = prev;
}

void deleteElement(int pos, struct Node *main_head)
{
    struct Node *before = main_head;
    struct Node *after = main_head;
    struct Node *tbd = main_head; //tbd : to be deleted

    if (pos > len(main_head))
    {
        printf("Position is beyond the current length");
        return;
    }

    /*else if(pos == 0)
    {
        deleteBeg(&main_head);
        return;
    }*/

    for (int i = 0; i < pos + 1; i++)
    {
        after = after->link;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        before = before->link;
    }

    for (int i = 0; i < pos; i++)
    {
        tbd = tbd->link;
    }

    before->link = after;

    free(tbd);
}

void deleteEnd(struct Node *main_head)
{
    struct Node *ptr = main_head;
    struct Node *last = main_head;

    for (int i = 0; i < len(main_head) - 2; i++)
    {
        ptr = ptr->link;
    }

    while (last->link != NULL)
    {
        last = last->link;
    }

    ptr->link = NULL; // Previous node

    free(last);
}

void deleteBeg(struct Node **main_head)
{
    struct Node *beg = *main_head;

    *main_head = beg->link;

    free(beg);
}

void insert_element(int pos, int val, struct Node **main_head)
{

    struct Node *ptr;
    struct Node *cur = *main_head;
    struct Node *before = *main_head;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = val;

    if (pos == 0)
    {
        ptr->link = *main_head;
        *main_head = ptr;
        return;
    }

    else if (pos == len(*main_head) - 1)
    {
        append(val, &*main_head);
        return;
    }

    else if (pos > len(*main_head))
    {
        printf("Cannot insert");
        return;
    }

    for (int i = 0; i < pos; i++)
    {
        cur = cur->link;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        before = before->link;
    }

    ptr->link = cur;    // Right side connection
    before->link = ptr; // Left side connection
}

void deleteKey(int key, struct Node *main_head)
{
    struct Node *before = main_head;
    struct Node *after = main_head;
    struct Node *tbd = main_head;

    int pos = 0;

    while (tbd->data != key)
    {
        tbd = tbd->link;
        pos++;
    }

    for (int i = 0; i < pos + 1; i++)
    {
        after = after->link;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        before = before->link;
    }

    before->link = after;
    free(tbd);
}

void descendingInsertion(int val, struct Node **main_head)
{
    struct Node *ptr = *main_head;
    int pos = 0;
    if (ptr == NULL)
    {
        append(val, &ptr);
        return;
    }

    while (ptr->data > val)
    {
        ptr = ptr->link;
        pos++;
    }

    insert_element(pos, val, &*main_head);
}

int main()
{
    struct Node *head;
    // struct Node *head_2;
    // int choice;
    // int data;
    /*
    while(1)
    {
        printf("1. Create a Linked List\n");
        printf("2. Display\n");
        printf("3. Push\n");
        printf("4. Append\n");
        printf("5. Concatenate\n");
        printf("Make a choice : "), scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter the data of the 1st Node: "),scanf("%d",&data);
            createLL(1,&head);
            printf("\n");
            break;

        case 2:
            display(head);
            printf("\n");
            break;

        case 3:
            printf("Enter Data: "),scanf("%d",&data);
            push(data,&head);
            printf("\n");
            break;

        case 4:
            printf("Enter Data: "), scanf("%d", &data);
            append(data, &head);
            printf("\n");
            break;

        case 5: 
            merge(&head,&head_2);

        default:
            break;
        }
    }
*/

    createLL(30, &head);
    //descendingInsertion(20,&head);
    //descendingInsertion(15,&head);
    //descendingInsertion(20,&head);
    //descendingInsertion(10,&head);

    display(head);
    return 0;
}