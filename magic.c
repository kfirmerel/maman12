#include "utils.h"

int main(int argc, char *argv[])   
{

    int i, j, temp, type, counter = 0;
    int matrix[N][N];
    int input[N*N*N];

    for (i = 0; i < N*N*N; i++) 
    {
        input[i] = INT_MIN;   
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = 0;
        }
    }   
    printf("Hello and welcome to the magic square test.\nPlease enter your matrix so that the numbers are provided in row order, from left to right in each row.\nFor example - input of: 1 2 3 4 5 6 7 8 9 \nIs represent the matrix that look like this:\n");
    printf("__________________\n");
    printf("1\t2\t3\n4\t5\t6\n7\t8\t9\n");
    printf("__________________\n");
    printf("The program is now suitable for matrix of %d*%d (%d numbers).\nThe numbers you enter need to be separated by space, tab or enter.\nWhen you finished press ctrl+d. \n",N,N,N*N);
    for (i = 0; i < N*N*N; i++)
    {
        type = scanf("%d", &temp);
        if (type == EOF)
        {
            break;
        }
        if (type != 1)
        {
            printf("\nprogram stopped - invalid input, you need to enter only integer\n");
            return 0;
        }
        input[i] = temp;
    }
    if (to_short(input)) 
    {
        printf("\nprogram stopped - your input is to short you need to enter %d numbers\n",N*N);
        return 0;
    }
    if (to_long(input)) 
    {
        printf("\nprogram stopped - your input is to long you need to enter %d numbers\n",N*N);
        return 0;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
                matrix[i][j] = input[counter];
                counter++;   
        }
    }
    printf("\nThe matrix you enterd is:\n");
    printmatrix(matrix);

    if (magic_check(matrix))
    {
        printf("Your matrix is a magic square\n");
    }
    else
    {
        printf("Your matrix is not a magic square\n");
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
