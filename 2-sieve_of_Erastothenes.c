#include <stdio.h>
#include <math.h>

// To Be Continued : Quite Tricky

int sieve(int n);

int main()
{
    int *main_arr;
    int i;
    *main_arr = sieve(101);

    printf("%d",main_arr[0]);

   
   return 0;
}

int sieve(int n)
{
    int A[n];
    int L[n];

    int p;
    int i;
    int j;

    for(p = 2 ; p<= n ; p++)
    {
        A[p] = p ;
    }

    for(p = 2 ; p <= floor(n) ; p++)
    {
        if(A[p] != 0)
        {
            j = p*p;

            while(j<=n)
            {
                A[j] = 0;
                j = j+p;
            }
        }
    }

    i = 0;
    for(p = 2 ; p<=n ; p++)
    {
        if(A[p] !=0)
        {
            L[i] = A[p];
            i+=1;
        }
    }

    return L;
}