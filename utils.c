#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

int magic_check(int matrix[N][N])
{
    int i, magic_sum = 0;
    for ( i = 0; i < N; i++) /*check one diagonal for magic sum*/
    {
        magic_sum += matrix[i][i];
    }
    
    return (rows_check(matrix, magic_sum) && coloums_check(matrix, magic_sum) && diagonals_check(matrix, magic_sum));
            
}
int rows_check(int matrix[N][N], int magic)
{
    int i, j, sum = 0;
    for ( i = 0 ; i < N ; i++)
    {    
        for ( j = 0; j < N; j++)
            sum += matrix[i][j];

        if (sum != magic)
        {
            return 0;
        }
        sum = 0;
    }
    return 1;
}

int coloums_check(int matrix[N][N], int magic)
{
    int i, j, sum = 0;
    for (i=0 ; i < N ; i++)
    {    
        for (j = 0; j < N; j++)
            sum += matrix[j][i];

        if (sum != magic)
        {
            return 0;
        }
        sum = 0;
    }
    return 1;
}

int diagonals_check(int matrix[N][N], int magic)
{
    int i, sum = 0;
    for(i = 0; i < N ; i++)
    {
        sum += matrix[i][i];
    }

    if( sum != magic )
        return 0;

    sum = 0;  
    for (i = 0; i < N; i++)
    {
       sum += matrix[N-i-1][i];
    }

    if (sum != magic)
    {
        return 0;
    }

    return 1;  
}

