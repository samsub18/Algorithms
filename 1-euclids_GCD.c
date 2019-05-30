#include <stdio.h>
#include <math.h>
#include <time.h>


int gcd(int a , int b); // Euclids method is awesome

int gcd_2(int a, int b); // Method 2 : Decrementing the minimum

int main()
{
    clock_t start,end;
    double time_taken;

    start = clock(); // Timer starts
    

    //printf("%d",gcd(31415,14142));

    printf("%d",gcd_2(31415,14142));
    end = clock();

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC ;
    
    printf("\nTime elapsed : %f",time_taken);
    
    return 0;
}

int gcd(int a, int b)
{
    int r;

    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }

    return a;
}

int gcd_2(int a , int b)
{
    int t;

    if (a<b)
    {
        t = b;
    }

    else
    {
        t = a;
    }

    while (1)
    {
        if(a%t == 0 && b%t ==0)
        {
            return t;
        }

        else
        {
            t--;
        }
        
    }
}