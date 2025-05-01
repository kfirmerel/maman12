#include "utils.h"
void printmatrix(int matrix[][N]) /*gest the matrix and print it in a nice visual way*/
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
int magic_check(int matrix[][N]) /*gets the matrix, return true if the matrix is magic square*/
{
    int i, magic_sum = 0;
    for ( i = 0; i < N; i++) /*check one diagonal for the initial magic sum*/
    {
        magic_sum += matrix[i][i];
    }
    
    return (is_valid(matrix) && rows_check(matrix, magic_sum) && columns_check(matrix, magic_sum) && diagonals_check(matrix, magic_sum)); 
            /* check if the matrix is valid and if all rows, columns and diagonals sum to the same value */
}
int rows_check(int matrix[][N], int magic) /*gest the matrix and the sum to check, return true if all rows sum is the same has the function gets*/
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
int columns_check(int matrix[][N], int magic) /*gest the matrix and the sum to check, return true if all columns sum is the same has the function gets*/
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
int diagonals_check(int matrix[][N], int magic) /*gest the matrix and the sum to check, return true if both diagonals sum is the same has the function gets*/
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
int is_valid(int matrix[][N]) /*gets the matrix, return true if the numbers besween 1-N*N and there is no number that appears more than once*/
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
int to_short(int input[]) /*gets the array of input, return true if it has less valeus then he should*/
{
    if(input [N*N-1] != INT_MIN) /* check if in the place of the N*N in the input array there is something that is not the MIN_INT , if so the user enter at least the right amount of numbers that needed */
    {
        return 0;
    }
    return 1;
}
int to_long(int input[]) /*gets the array of input, return true if it has more valeus then he should*/
{
    if (input[N*N] != INT_MIN) /* check if in the place of the N*N+1 in the input array there is something that is not the MIN_INT, if so the user enter more then numbers that needed*/
    {
        return 1;
    }
    return 0;
}
