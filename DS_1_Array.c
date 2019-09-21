#include <stdio.h>
#include <stdlib.h>

struct ArrayList {
    int *a;
    int count;
};

struct ArrayList *a1;

void createList(int length) {
    a1 = (struct ArrayList *)malloc(sizeof(struct ArrayList));
    a1->count = length;
    a1->a = (int *)malloc((a1->count) * sizeof(int));
}

void insertElement(int val, int pos)
{
    
    int i;
    for(i =0 ; i<a1->count; i++)
    {
        if(i == pos)
        {
            a1->a[pos] = val; 
        }
    }
}

void display()
{
    int i;
    for(i = 0 ; i<a1->count ; i++)
    {
        printf("%d ",a1->a[i]);
    }
}

void deleteELement(int pos)
{
    
}

int main()
{
    createList(4);
    insertElement(1,0);
    insertElement(2,1);
    display();

    return 0;
}