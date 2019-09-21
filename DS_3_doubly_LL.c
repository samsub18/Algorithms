#include <stdio.h>
#include <stdlib.h>

// Create a node 

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void display(struct Node *node)
{
    struct Node *last;
    printf("Traversal in forward direction:\n");
    while(node != NULL)
    {
        printf("%d-->",node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
    printf("Traversal in reverse: \n");
    while(last != NULL)
    {
        printf("%d-->",last->data);
        last = last->prev;
    }

    printf("\n");
}


void push(int data, struct Node **main_head)
{
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = (*main_head);
    if(*main_head != NULL)
    {
        (*main_head)->prev = node;
    }
    (*main_head) = node;
}


void append(int data, struct Node **main_head)
{
    struct Node *node;
    struct Node *last = *main_head;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;  // Step 1: Initializing the data
    node->next = NULL;  // Step 2: Next of node->NULL

    if(last == NULL)
    {
        *main_head = node;
        return;
    }

    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = node;
    node->prev = last;

}

void deleteEnd(struct Node *main_head)
{
    struct Node *last = main_head;
    
    while(last->next != NULL)
    {
        last = last->next;
    }

    last->prev->next = NULL;
    free(last);
}

void deleteBeg(struct Node **main_head)
{
    struct Node *node = *main_head;
    *main_head = node->next;
    node->next->prev = NULL;
    free(node);
}

void insertAfter(struct Node *node, int data)
{
    if(node->prev == NULL)
    {
        printf("Cant insert After");
        return;
    }
    struct Node *new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data; // Step 1

}

 

int main()
{
    struct Node *head = NULL;
    push(1,&head);
    push(2,&head);
    display(head);
    append(101,&head);
    append(201,&head);
    append(301,&head);
    deleteEnd(head);
    deleteBeg(&head);
    deleteBeg(&head);
    display(head);
    return 0;
}