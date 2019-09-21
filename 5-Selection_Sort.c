#include <stdio.h>
#include <stdlib.h>

// We are traversing the array and finding the smallest element and swapping it 

void swap(int *a , int *b)
{
    int temp;
    temp = *a;
    *a = *b ;
    *b = temp;
}

int main()
{
    int i,j,n;
    int min;
    int arr[] = {89,23,17,101,42,19};
    n = sizeof(arr)/sizeof(arr[0]);

    for(i = 0 ; i < n-1 ; i++)
    {
        min = i;

        for(j=i+1 ; j<n ; j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }

    for (i=0 ; i<n ; i++)
    {
        printf("%d\n",arr[i]);
    }


    return 0;
}