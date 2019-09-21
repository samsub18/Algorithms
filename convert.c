#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char source[] = " a + b * {c ^ d - e} ^ [f + g * h] - i ";
    char target[2000];

    for(int i = 0 ; i<strlen(source) ; i++)
    {
        if (source[i] == '{' || source[i] == '[')
        {
            target[i] = '(';
        }

        else if (source[i] == '}' || source[i] == ']')
        {
            target[i] = ')';
        }

        else
        {
            target[i] = source[i];
        }
    }

    printf("%s\n",target);
    printf("%s",source);

    return 0;
}