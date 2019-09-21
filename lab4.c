#include <stdio.h>
#include <stdlib.h>
#define debug printf("Here")

// Node of the linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Handle of the list. Its head points to the first node in the list.
typedef struct DLList
{
    Node *head;
    int number_of_nodes;
} DLList;

// initializes a linked list
DLList *initialize_list();

// Creates a node and stores the data in it.
Node *create_node(int data);

// Inserts data at the beginning of the DLList
void insert_back(DLList *dll, int data);

// Deletes the node at position pos. No operation if pos is out of range.
void delete_back(DLList *dll);

// Return index of key in the list(0-based). Return -1 if not found
void reverse_list(DLList *dll);

// Prints the entire list. Prints "EMPTY" if the list is empty.
void display(DLList *dll);

// Deallocates resources held by the list
void destroy_list(DLList *);

int main()
{
    DLList *dll = initialize_list();
    int ele, choice;

    do
    {
        scanf("%d", &choice);

        switch (choice)
        {
        // Insert at the end of the list
        case 1:
            scanf("%d", &ele);
            insert_back(dll, ele);
            break;

        // Delete at the end of the list
        case 2:
            delete_back(dll);
            break;

        // Search for element
        case 3:
            reverse_list(dll);
            break;

        // Print entire list
        case 4:
            display(dll);
            break;
        }
    } while (choice != 0);

    destroy_list(dll);
    return 0;
}

DLList *initialize_list()
{
    DLList *ptr;
    ptr = (DLList *)malloc(sizeof(DLList));
    ptr->head = NULL;
    return ptr;
}

Node *create_node(int data)
{
    Node *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insert_back(DLList *dll, int data)
{

    Node *ptr = create_node(data);
    Node *last = dll->head;
    ptr->next = NULL;

    if (last == NULL)
    {
        dll->head = ptr;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = ptr;
    ptr->prev = last;
}

void delete_back(DLList *dll)
{
    if (dll->head == NULL)
    {
        return;
    }

    if (dll->head->next == NULL)
    {
        dll->head = NULL;
        return;
    }

    Node *last = dll->head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->prev->next = NULL;
    free(last);
}

void reverse_list(DLList *dll)
{
    if (dll->head == NULL)
    {
        return;
    }
    Node *cur = dll->head;
    Node *prev = NULL;
    Node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next; 

        //--This is where the switching happens---
        cur->next = prev; 
        cur->prev = next;
        //----------------------------------------
        
        prev = cur;
        cur = next;
    }

    dll->head = prev;
}

void display(DLList *dll)
{
    Node *ptr = dll->head;

    if (ptr == NULL)
    {
        printf("EMPTY\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void destroy_list(DLList *dll)
{
    free(dll);
}