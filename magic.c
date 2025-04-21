/* program that ask the client for a matrix and tell him if this matrix is a magic square*/

#include "utils.h"

int main(int argc, char *argv[])   
{

    int i, j; /* i,j - to use in the loops */
    int temp; /* to hold the inpur for checks before insert to the array */
    int type; /* to hold the return value of scanf */
    int counter = 0; /* to count the numbers allready inserted into the matrix */
    int input[N*N*N]; /* array to hold the input numbers */
    int matrix[N][N]; /* matrix to arrange the input*/

    for (i = 0; i < N*N*N; i++) /* initialize the input array with number that is not in use */  
    {
        input[i] = INT_MIN;   
    }

    for (i = 0; i < N; i++) /* initialize the matrix with 0 */
    {
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = 0;
        }
    }   
    printf("Hello and welcome to the magic square test.\n");
    printf("Please enter your matrix so that the numbers are provided in row order, from left to right in each row.\n");
    printf("For example - input of: 1 2 3 4 5 6 7 8 9 \n");
    printf("represent the matrix that look like this:\n");
    printf("__________________\n");
    printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n");
    printf("__________________\n");
    printf("The program is now suitable for matrix of %d*%d (%d numbers).\n",N,N,N*N);
    printf("The numbers you enter need to be separated by space, tab or enter.\n");
    printf("When you finished press ctrl+d. \n");
    printf("__________________\n");

    for (i = 0; i < N*N*N; i++) /* loop to get the input from the user */
    {
        type = scanf("%d", &temp); 
        if (type == EOF) /* check if the user finished the input */
        {
            break;
        }
        if (type != 1) /* check if the input is an integer */
        {
            printf("\nProgram stopped - invalid input, you need to enter only integers\n");
            return 0;
        }
        input[i] = temp; /* insert the input to the array after the checks */
    }
    if (to_short(input)) /* check if the input is too short */
    {
        printf("\nProgram stopped - your input is to short, you need to enter %d numbers\n",N*N);
        return 0;
    }
    if (to_long(input)) /* check if the input is too long */
    {
        printf("\nProgram stopped - your input is to long, you need to enter %d numbers\n",N*N);
        return 0;
    }

    for (i = 0; i < N; i++) /* loop to insert the input to the matrix */
    {
        for (j = 0; j < N; j++)
        {
                matrix[i][j] = input[counter];
                counter++;   
        }
    }
    printf("\nThe matrix you enterd is:\n");
    printmatrix(matrix);

    if (magic_check(matrix)) /* check if the matrix is a magic square */
    {
        printf("Your matrix is a magic square\n");
    }
    else
    {
        printf("Your matrix is not a magic square\n");
    }
    return 0;
}