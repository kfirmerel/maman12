#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"



int main(int argc, char *argv[])   
{

    int i, j;
    int matrix[N][N];

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = 1;
        }
    }

    matrix[0][1] = 2;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    if (magic_check(matrix))
    {
        printf("big sucsses\n");
    }
    else
    {
        printf("big fail\n");
    }
    return 0;
}
/*
////////////////////////////////////////////
    int matrix[N][N];
    int i = 1, size = 0;
    for (i = 1; i < argc; i++) 
    {
        if (!strcmp(argv[i], "-size") && argc > i + 1)
            size = atoi(argv[i + 1]);   
    }
    printf("argc = %d\nsize = %d\n", argc, size);
    return 0;
*/
