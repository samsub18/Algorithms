#include <stdio.h>
#include <stdlib.h>

int main()
{
   int arr[] = {1,2,3,4,5,6};
   int len = sizeof(arr)/sizeof(arr[0]);

    int valToBeSearched ;
    scanf("%d",&valToBeSearched);

    for (int i = 0 ; i < len ; i++)
    {
        if (arr[i] == valToBeSearched)
        {
            printf("%d found at index %d",valToBeSearched,i);
            break;
        }
    }

    return 0;
}