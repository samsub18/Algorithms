#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int capacity;
    int *arr;
};

int isFull(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

struct Stack * createStack(int capacity)
{
    struct Stack *stack;
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(capacity * sizeof(int));
    return stack;
}

void push(struct Stack *stack, int data)
{
    if(!isFull(stack))
    {
        stack->arr[++stack->top] = data;
    }

    else
    {
        printf("Overflow!\n");
    }
}

void pop(struct Stack *stack)
{
    if(!isEmpty(stack))
    {
        stack->top--;
    }

    else
    {
        printf("Underflow");
    }
    
}

void display(struct Stack *stack)
{
    int i = 0 ;
    while(i<=stack->top)
    {
        printf("%d ",stack->arr[i]);
        i++;
    }
    printf("\n");
}


int main()
{
    struct Stack *main_stack = createStack(4);  // Created stack with a capacity of 4
    push(main_stack,1);
    push(main_stack,2);
    push(main_stack,3);
    push(main_stack,4);
   // push(main_stack,5);
    //push(main_stack,6);
    pop(main_stack);
    display(main_stack);
    return 0;
}