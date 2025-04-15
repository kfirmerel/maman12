#include "utils.h"
void printmatrix(int matrix[][N])
{
    int i, j;
    printf("_____________________\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("_____________________\n");
}
int magic_check(int matrix[][N])
{
    int i, magic_sum = 0;
    for ( i = 0; i < N; i++) /*check one diagonal for the magic sum*/
    {
        magic_sum += matrix[i][i];
    }
    
    return (is_valid(matrix) && rows_check(matrix, magic_sum) && coloums_check(matrix, magic_sum) && diagonals_check(matrix, magic_sum));
            
}
int rows_check(int matrix[][N], int magic)
{
    int i, j, sum = 0;
    for ( i = 0 ; i < N ; i++)
    {    
        for ( j = 0; j < N; j++)
        {
            sum += matrix[i][j];
        }
        if (sum != magic)
        {
            return 0;
        }
        sum = 0;
    }
    return 1;
}
int coloums_check(int matrix[][N], int magic)
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
int diagonals_check(int matrix[][N], int magic)
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
int is_valid(int matrix[][N])
{
    int i, j;
    int counter[N*N+1];
    for (i = 0; i < N*N+1; i++) /* initialize the counter */
    {
        counter[i] = 0;
    }

    for(i = 0; i < N; i++) /* check if the numbers are in the range of 1 to N*N */
    {
        for(j = 0; j < N; j++)
        {
            if (matrix[i][j] < 1 || matrix[i][j] > N*N)
            {
                return 0;
            }
        }
    }
    
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (counter[matrix[i][j]] == 0)
                counter[matrix[i][j]] = 1;
            else
            {
                return 0;
            }
        }    
    }      
    return 1;
}
int to_short(int input[])
{
    int i;
    for (i = 0; i < N*N; i++)
    {
        if (input[i] == INT_MIN)
        {
            return 1;
        }
    }
    return 0;
}
int to_long(int input[])
{
    if (input[N*N] != INT_MIN)
    {
        return 1;
    }
    return 0;
}
