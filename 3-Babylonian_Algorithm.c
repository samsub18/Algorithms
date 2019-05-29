#include <stdio.h>
#include <math.h>

float baby_sqrt(float n);


int main()
{
    float ans;

    ans = baby_sqrt(2);

    printf("%f",ans);

    return 0;
}

float baby_sqrt(float n)
{
    float x = n; // Closest approx
    float y = 1; // Any intialisation is not fine
    float e = 0.0000000000000001; // Accuracy

    while ((x-y)>e)
    {
        x = (x+y)/2;
        y = n/x;
    }

    return x;
}