#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int capacity;
    int top;
    int *arr;
};

struct Stack* createStack(int capacity)
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(capacity * sizeof(int));

    if (!stack->arr)
        return NULL;
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

int isFull(struct Stack *stack)
{
    return stack->top = stack->capacity - 1;
}

int peek(struct Stack *stack)
{
    return stack->arr[stack->top];
}

void pop(struct Stack *stack)
{
    if(!isEmpty(stack))
    {
        stack->arr[stack->top--];
    }
    return ;
}

void push(struct Stack *stack, char c)
{
     stack->arr[++stack->top] = c;

}

int isOperand(char c)
{
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

int power(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char* source , char* target)
{
    int i,k;

    for ( i = 0; i < strlen(source); i++)
    {
        if (source[i] == '{' || source[i] == '[')
        {
            target[i] = '(';
        }

        else if (source[i] == '}' || source[i] == ']')
        {
            target[i] = ')';
        }

        else
        {
            target[i] = source[i];
        }
    }

    target[strlen(source)] = '\0';
    

    struct Stack *stack = createStack(strlen(source));
    if (!stack) // See if stack was created successfully
        return ;

    for(i = 0 , k = -1 ; target[i] ; ++i)
    {
        
        if(isOperand(target[i]))
        {
            target[++k] = target[i];
        }

        else if(target[i] == '(')
        {
            push(stack,target[i]);
        }

        else if(target[i] == ')')
        {
            while(!isEmpty(stack) && peek(stack)!='(')
            {
                target[++k] = stack->arr[stack->top--];
            }
            
            if(!isEmpty(stack) && peek(stack)!='(' )
            {
                return ; // invalid
            }

            else
            {
                stack->arr[stack->top--]; // to remove '('
            }
        }

        else
        {
            while(!isEmpty(stack) && power(target[i]) <= power(peek(stack)))
            {
                target[++k] = stack->arr[stack->top--];
            }
            push(stack, target[i]);
        }
        
    }

    while(!isEmpty(stack))
    {
        target[++k] = stack->arr[stack->top--];
    }

    target[++k] = '\0';
    
}

int main()
{
    char source[2000] = "a+b*(c^d-e)^(f+g*h)-i";
    char target[2000];
    infixToPostfix(source,target);
    printf("%s", target);

    return 0;
}