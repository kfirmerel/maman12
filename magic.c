#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])   
{
    int i = 1, size = 0;
    for (i = 1; i < argc; i++) 
    {
        if (!strcmp(argv[i], "-size") && argc > i + 1)
            size = atoi(argv[i + 1]);   
    }
    printf("argc = %d\nsize = %d\n", argc, size);
    return 0;
}