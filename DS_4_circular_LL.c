// Polynomial addition using circular LL
// HW : Polynomial addition using SLL , polynomial addition using CLL
// What all did we do in DLL??
// addition and deletion at different points

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void createCll(struct Node *main_head)
{
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->link = NULL;
    main_head = ptr;
}

void display(struct Node *main_head)
{
    struct Node *ptr = main_head;
    do
    {
        printf("%d-->",ptr->data);
        ptr = ptr->link;
    } while (ptr != main_head);
    
}

void append(int data, struct Node **main_head)
{
    struct Node *new_node;
    struct Node *last = *main_head;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->link = NULL; // Let it point to NULL first

    if(last == NULL)
    {
        *main_head = new_node;
        new_node->link = *main_head;
        return;
    }

    while(last->link != *main_head)
    {
        last = last->link;
    }

    last->link = new_node;
    new_node->link = *main_head;
}

void insertAtPos(int data , int pos, struct Node **main_head)
{
    
}


int main()
{
    struct Node *head = NULL;
    append(1,&head);
    append(2,&head);
    display(head);
    return 0;
}