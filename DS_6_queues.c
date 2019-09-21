// Linear data structure 
// FIFO : First in first out 
// Simple queue

#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int rear;
    int front;
    int capacity;
    int *arr;
};

int isFull(struct Queue *q)
{
    return (q->rear == q->capacity - 1);
}

int isEmpty(struct Queue *q)
{
    return (q->rear == -1);
}

struct Queue* createQueue (int capacity)
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->arr = (int *)malloc(q->capacity * sizeof(int));
    q->front = -1;
    q->rear = -1;
    return q;
}

void insert_at_rear(struct Queue *q, int data)
{
    if(!isFull(q))
    {
        if(q->rear == -1)
        {
            q->front = 0;
        }

        q->arr[++q->rear] = data;
    }
}


void delete_at_beg(struct Queue *q)
{

    if(!isEmpty(q))
    {
        int j = 1;
       
        for(int i = 0 ; i<q->rear ; i++)
        {
            if(j<=q->rear)
            {
                q->arr[i] = q->arr[j];
                j++;
            }
        }
        q->rear--;
        
    }

}

void display(struct Queue *q)
{
    for(int i = 0 ; i<=q->rear ; i++)
    {
        printf("%d-->",q->arr[i]);
    }
}

int main()
{
    struct Queue *q1 = createQueue(4);
    insert_at_rear(q1,1);
    insert_at_rear(q1,2);
    insert_at_rear(q1,3);
    delete_at_beg(q1);
    delete_at_beg(q1);
    delete_at_beg(q1);
    display(q1);
    return 0;
}