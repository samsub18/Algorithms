#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

typedef struct List
{
    Node *head;
    int number_of_nodes;
} List;

/* initializes a linked list */
List *list_initialize();

/* Inserts a new node with data at the beginning */
void list_insert_beginning(List *list, int data);

/* Removes the last node of the linked list */
void list_delete_rear(List *list);

/* Print the contents of a list */
void list_print(List *list);

/* deallocates resources held by the list */
void list_destroy(List *list);

int main()
{
    int choice;
    List *list = list_initialize();
    do
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int element;
        case 1:
            /* Insert an element at beginning of the list */
            scanf("%d", &element);
            list_insert_beginning(list, element);
            break;
        case 2:
            /* Remove rear elements */
            list_delete_rear(list);
            break;
        case 3:
            /* Print list contents */
            list_print(list);
            break;
        default:
            list_destroy(list);
            break;
        }
    } while (choice >= 1 && choice < 4);

    return 0;
}
//DO NOT MODIFY THE ABOVE CODE.
//WRITE YOUR CODE BELOW.

List *list_initialize()
{
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    list->number_of_nodes = 0;
    return list;
}

void list_insert_beginning(List *list, int data)
{
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    new_node->link = list->head;
    list->head = new_node;
}

void list_delete_rear(List *list)
{
    Node *temp = list->head;

    if (list->head == NULL)
    {
        return;
    }

    else if (temp->link == NULL)
    {
        free(temp);
        list->head = NULL;

        return;
    }

    else
    {

        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }

        free(temp->link);
        temp->link = NULL;
    }
}

void list_print(List *list)
{
    Node *last = list->head;

    if (list->head == NULL)
    {
        printf("EMPTY\n");
        return;
    }

    while (last != NULL)
    {
        printf("%d ", last->data);
        last = last->link;
    }
    printf("\n");
}

void list_destroy(List *list)
{
    free(list);
}
