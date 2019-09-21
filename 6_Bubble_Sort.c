#include <stdio.h>
#include <stdlib.h>

void swap(int *a , int *b)
{
    int temp;
    temp = *a ;
    *a = *b;
    *b = temp;
}


int main()
{
    int i,j,n;
    int arr[] = {89,23,17,101,42,19};
    n = sizeof(arr)/sizeof(arr[0]);

    for (i = 0 ; i<n-1 ; i++)
    {
        for(j = 0 ; j< n-i-1 ; j++)
        {
            if(arr[j+1]<arr[j])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }

    for(i = 0 ; i <n ; i++)
    {
        printf("%d\n",arr[i]);
    }

    return 0;
}