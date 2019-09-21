/*

Basic Logic :
    1. Compare the expoenents 
    2. 3 cases:
        i. If poly exp 1 > poly exp 2 :
                append(poly data 1, &head_final)
            
           Else if poly exp 1 < poly exp 2:
                append(poly data 2, &head_fianl)

           Else if poly exp 1 == poly exp 2:
                add_append(poly_data1 + poly data 2 , &head_final)

    
    Methodology:

    5x^3 + 3x + 2;
    7x^7 + 4x^3 

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *link;
};

void createPoly(int cf, int ex, struct Node **main_head)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->link = NULL;
    ptr->coeff = cf;
    ptr->exp = ex;
    *main_head = ptr;
}

void appendPoly(int cf, int ex, struct Node **main_head)
{
    struct Node *last;
    struct Node *ptr;
    last = *main_head;



    if(last == NULL)
    {
        *main_head = 
    }
}


int main()
{
    struct Node *head1;
    struct Node *head2;
    struct Node *head_final;

}