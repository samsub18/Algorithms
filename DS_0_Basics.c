/*
    1. Structs 
    2. Union
    3. Enumeration constants 

    int a ; ->static memory : Name , address , value
            ->Dynamic memory : Address, value

*/

/*
#include <stdio.h>
#include <stdlib.h>

struct Student {
    int srn;
    int name[50];
};

int main()
{
   int a[] = {1,2,3};
   int len = sizeof(a)/sizeof(a[0]);
   int *ptr[len];

   for (int i = 0 ; i<len; i++)
   {
       ptr[i] = &a[i];
   }


   return 0 ;
}
*/

#include <stdio.h>
#include <stdlib.h>

// HW : Matrix multiplication by DMA.

int main()
{
    int r1,c1,r2,c2,i,j,k;
    printf("Enter the value of r1,c1,r2,c2: ") , scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    int ctr = 0;
 
    if (c1!=r2)
    {
        printf("Cannot multiply matrices !!");
        return 0;
    }
    int **mat1;
    int **mat2;
    int **mat3;
    
    mat1 = (int **)malloc(r1*sizeof(int*));
    mat2 = (int **)malloc(r2*sizeof(int*));
    mat3 = (int **)malloc(r1*sizeof(int*));

    for(i=0 ; i<r1 ; i++)
    {
        mat1[i] = (int *)malloc(c1*sizeof(int));
    }

    for(i = 0 ; i<r2 ; i++)
    {
        mat2[i] = (int *)malloc(c2*sizeof(int));
    }

    for(i = 0 ; i<r1 ; i++)
    {
        mat3[i] = (int *)malloc(c2*sizeof(int));
    }

    for (i =0 ; i<r1 ; i++)
    {
        for(j = 0 ; j<c1 ; j++)
        {

            printf("Enter the elements for mat1: "),scanf("%d",&mat1[i][j]);
        }
    }

    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("Enter the elements for mat2: "), scanf("%d", &mat2[i][j]);
        }
    }
                                             
    for(i = 0 ; i<r1 ; i++)
    {
        for(j= 0 ; j<c1 ; j++)
        {
            mat3[i][j] = 0;
            for (k = 0 ; k<c2 ;  k++)
            {
                mat3[i][j] = mat3[i][j] + (mat1[i][k] * mat2[k][j]);
            }
        }
    }

    for(i = 0; i<r1; i++)
    {
        for (j = 0 ; j<c2 ; j++)
        {
            ctr++;
            printf("%d\t",mat3[i][j]);
            if (ctr%3 == 0 )
            {
                printf("\n");
            }

        }
    }

    return 0;
}