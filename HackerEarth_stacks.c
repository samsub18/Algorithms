#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure using an array
typedef struct Stack
{
    int *arr;
    int top;
} Stack;

// Initialise a Stack of given size
Stack *stack_initialize(int);

// Push an element onto the Stack
void stack_push(Stack *, int);

// Pop an element from the Stack. Do not return the element
void stack_pop(Stack *);

// Check if the Stack is empty
int stack_is_empty(Stack *);

// Return the top element of the Stack
int stack_peek(Stack *);

// Free the resources held by the Stack
void stack_destroy(Stack *);

// Convert an infix expression to postfix expression
void convert_infix_to_postfix(char *, char *);

// Check Precedence
int Prec(char);

// To Check is Operand
int isOperand(char);

int main()
{
    char source_infix[2000];
    char target_postfix[2000];
    int number_of_inputs = 0;
    scanf("%d", &number_of_inputs);
    for (int counter = 0; counter < number_of_inputs; ++counter)
    {
        scanf("%s", source_infix);
        convert_infix_to_postfix(source_infix, target_postfix);
        printf("%s\n", target_postfix);
    }
    return 0;
}

Stack *stack_initialize(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack)
        return NULL;
    stack->top = -1;
    stack->arr = (int *)malloc(size * sizeof(int));

    if (!stack->arr)
        return NULL;

    return stack;
}

int stack_is_empty(Stack *ptr_stack)
{
    return ptr_stack->top == -1;
}

void stack_push(Stack *ptr_stack, int key)
{
    ptr_stack->arr[++ptr_stack->top] = key;
}

void stack_pop(Stack *ptr_stack)
{
    if (!stack_is_empty(ptr_stack))
    {
        ptr_stack->arr[ptr_stack->top--];
    }
    return;
}

int stack_peek(Stack *ptr_stack)
{
    return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(Stack *ptr_stack)
{
    ptr_stack = NULL;
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '/':
    case '*':
        return 2;
    }
    return -1;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void convert_infix_to_postfix(char *source_infix, char *target_postfix)
{
    int i, k;

    for (i = 0; i < strlen(source_infix); i++)
    {
        if (source_infix[i] == '{' || source_infix[i] == '[')
        {
            target_postfix[i] = '(';
        }

        else if (source_infix[i] == '}' || source_infix[i] == ']')
        {
            target_postfix[i] = ')';
        }

        else
        {
            target_postfix[i] = source_infix[i];
        }
    }

    target_postfix[strlen(source_infix)] = '\0';

    Stack *stack = stack_initialize(strlen(target_postfix));
    if (!stack)
    {
        return;
    }

    for (i = 0, k = -1; target_postfix[i]; ++i)
    {
        if (isOperand(target_postfix[i]))
        {
            target_postfix[++k] = target_postfix[i];
        }

        else if (target_postfix[i] == '(')
        {
            stack_push(stack, target_postfix[i]);
        }

        else if (target_postfix[i] == ')')
        {
            while (!stack_is_empty(stack) && stack_peek(stack) != '(')
            {
                target_postfix[++k] = stack->arr[stack->top--];
            }

            if (!stack_is_empty(stack) && stack_peek(stack) != '(')
            {
                return;
            }

            else
            {
                stack->arr[stack->top--];
            }
        }

        else
        {
            while (!stack_is_empty(stack) && Prec(target_postfix[i]) <= Prec(stack_peek(stack)))
            {
                target_postfix[++k] = stack->arr[stack->top--];
            }
            stack_push(stack, target_postfix[i]);
        }
    }

    while (!stack_is_empty(stack))
    {
        target_postfix[++k] = stack->arr[stack->top--];
    }
    target_postfix[++k] = '\0';
}
