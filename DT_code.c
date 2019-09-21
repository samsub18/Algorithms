

#include <stdio.h>
#include <stdlib.h>

// HW : Matrix multiplication by DMA.

int main()
{
    int r1, c1, r2, c2, i, j, k;
    // printf("Enter the value of r1,c1,r2,c2: ") , scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    r1 = 3;
    c1 = 3;
    r2 = 3;
    c2 = 3;
    int ctr = 0;
    int mat_ctr = 1;

    if (c1 != r2)
    {
        printf("Cannot multiply matrices !!");
        return 0;
    }
    int **mat1;
    int **mat2;
    int **mat3;

    mat1 = (int **)malloc(r1 * sizeof(int *));
    mat2 = (int **)malloc(r2 * sizeof(int *));
    mat3 = (int **)malloc(r1 * sizeof(int *));

    for (i = 0; i < r1; i++)
    {
        mat1[i] = (int *)malloc(c1 * sizeof(int));
    }

    for (i = 0; i < r2; i++)
    {
        mat2[i] = (int *)malloc(c2 * sizeof(int));
    }

    for (i = 0; i < r1; i++)
    {
        mat3[i] = (int *)malloc(c2 * sizeof(int));
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {

            mat1[i][j] = mat_ctr;
            mat_ctr++;
        }
    }

    mat_ctr = 1;

    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            mat2[i][j] = mat_ctr;
            mat_ctr++;
        }
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            mat3[i][j] = 0;
            for (k = 0; k < c2; k++)
            {
                mat3[i][j] = mat3[i][j] + (mat1[i][k] * mat2[k][j]);
            }
        }
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            ctr++;
            printf("%d\t", mat3[i][j]);
            if (ctr % 3 == 0)
            {
                printf("\n");
            }
        }
    }

    return 0;
}