#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // ------------------------------Input Section-----------------------//
    int n,d,m;
    int i,j;

    int sum , bingo;

    sum = 0;
    bingo = 0;

    scanf("%d",&n);

    int bar[n];

    for(i = 0; i<n ; i++)
    {
        scanf("%d",&bar[i]);
    }

    scanf("%d %d",&d,&m);
    
    // -----------------------------Algorithm---------------------------//

    // Main Logic : Length = birth month (m)  && Sum = Birth day (d)

    for (i = 0 ; i<n ; i++)
    {
        for(j = i ; j<m+i ; j++)
        {
            sum = sum + bar[j];    
        }

        if (sum == d)
        {
            bingo+=1;
        }

        sum = 0;

    }

    printf("%d",bingo);
    
    return 0;
}

