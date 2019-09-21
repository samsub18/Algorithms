// Solution to original problem can be solved using a sub-problem 
// Base case -> is important !! 
// How to convert from recursive to iterative

#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    if(n == 1)
    {
        return 1;
    }

    else
    {
        return n*fact(n-1);
    }
    
}

int main()
{
    int n= 5;
    int out;

    out = fact(n);

    printf("%d",out);
}