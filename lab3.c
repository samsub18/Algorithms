#include <stdio.h>
#include <stdlib.h>

// struct Node --> Node
// struct List --> List

/*

Custom input :


*/

// Node of the linked list
typedef struct Node
{
    int data;
    struct Node *link;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct List
{
    Node *head;
    int number_of_nodes;
} List;

// Initializes a linked list
List *list_initialize();

// Creates a node and stores the data
Node *create_node(int);

// Deletes the node at the given position
// Does not delete anything if position is out of range
void del_at_pos(int, List *);

// Displays the contents of the linked list in space seperated manner.
void display(List *);

// Inserts an element into an ordered linked list.
void insert_in_order(int, List *);

// Returns the index of the key in the linked list.
// Returns -1 if key not found
int find_key(int, List *);

// Destroy the list by freeing all the nodes.
void destroy_list(List *);

int main()
{
    int choice, element, position, index;

    // Initialize an empty list.
    List *sll = list_initialize();
    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
        // Delete at given position
        case 1:
        {
            scanf("%d", &position);
            del_at_pos(position, sll);
        }
        break;

        // Insert element into the ordered list.
        case 2:
        {
            scanf("%d", &element);
            insert_in_order(element, sll);
        }
        break;

        // Display the list.
        case 3:
        {
            display(sll);
        }
        break;

        // Find the given key.
        case 4:
        {
            scanf("%d", &element);
            index = find_key(element, sll);
            printf("%d\n", index);
        }
        break;

        default:
            break;
        }
    } while (choice != 0);

    destroy_list(sll);

    return 0;
}

List *list_initialize()
{
    List *ptr;
    ptr = (List *)malloc(sizeof(List));
    ptr->head = NULL;
    ptr->number_of_nodes = 0;
    return ptr;
}

Node *create_node(int data)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->link = NULL;
    return node;
}

void display(List *sll)
{
    Node *ptr;
    ptr = sll->head;

    if (ptr == NULL)
    {
        printf("\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void del_at_pos(int position, List *sll)
{
    if (sll->head == NULL)
    {
        return;
    }

    if (position <= 0)
    {
        return;
    }

    Node *cur = sll->head;
    Node *prev = sll->head;
    Node *next = sll->head;
    Node *last = sll->head;

    int len, i;
    len = 0;
    while (last != NULL)
    {
        len++;
        last = last->link;
    }

    if (position == 1)
    {
        sll->head = cur->link;
        free(cur);
        return;
    }

    else if (position == len)
    {
        for (i = 0; i < len - 2; i++)
        {
            cur = cur->link;
        }

        while (next->link != NULL)
        {
            next = next->link;
        }

        cur->link = NULL;

        free(next);
        return;
    }

    else if (position > len)
    {
        return;
    }

    for (i = 0; i < position - 1; i++)
    {
        cur = cur->link;
    }

    for (i = 0; i < position - 2; i++)
    {
        prev = prev->link;
    }

    for (i = 0; i < position; i++)
    {
        next = next->link;
    }

    prev->link = next;
    free(cur);
}

void insert_in_order(int element, List *sll)
{

    int i;
    int pos = 0;
    int len = 0;
    Node *last = sll->head;
    Node *ptr = create_node(element);
    Node *cur = sll->head;
    Node *prev = sll->head;
    if (last == NULL)
    {
        sll->head = ptr;
        return;
    }

    while (last != NULL && element <= last->data)
    {
        last = last->link;
        pos++;
    }

    last = sll->head;

    while (last != NULL)
    {
        last = last->link;
        len++;
    }

    last = sll->head;

    if (pos == 0)
    {
        ptr->link = sll->head;
        sll->head = ptr;
    }

    else if (pos == len)
    {
        while (last->link != NULL)
        {
            last = last->link;
        }
        last->link = ptr;
    }

    else
    {
        for (i = 0; i < pos; i++)
        {
            cur = cur->link;
        }

        for (i = 0; i < pos - 1; i++)
        {
            prev = prev->link;
        }

        ptr->link = cur;
        prev->link = ptr;
    }
}

int find_key(int key, List *sll)
{

    Node *ptr = sll->head;
    int index = 0;

    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            return index;
        }
        index++;
        ptr = ptr->link;
    }

    return -1;
}

void destroy_list(List *sll)
{
    /*
    Node *cur;
    Node *next;
    cur = sll->head;
    while(cur!=NULL)
    {
        next = cur->link;
        free(cur);
        cur = next;
    }
    
    sll->head = NULL;
    */
    free(sll);
    sll->number_of_nodes = 0;
}