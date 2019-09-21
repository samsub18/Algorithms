#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
     
    char str[] = "Hey-there";
    char *token = strtok(str, "-");
    token = strtok(NULL, "-");
    token = strtok(NULL, "-");
    printf("%s",token);
    

    printf("\n");
    return 0;
}