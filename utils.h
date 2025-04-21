#define N 3 /*matrix length*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

void printmatrix(int matrix[][N]);/*gest the matrix and print it in a nice cisual way*/
int magic_check(int matrix[][N]); /*gets the matrix, return true if the matrix is magic square*/
int rows_check(int matrix[][N], int magic); /*gest the matrix and the sum to check, return true if all rows sum is the same has the function gets*/
int columns_check(int matrix[][N], int magic);/*gest the matrix and the sum to check, return true if all columns sum is the same has the function gets*/
int diagonals_check(int matrix[][N], int magic);/*gest the matrix and the sum to check, return true if both diagonals sum is the same has the function gets*/
int is_valid(int matrix[][N]);/*gets the matrix, return true if the numbers besween 1-N*N and there is no number that appears more than once*/
int to_short(int input[]);/*gets the array of input, return true if it have less valeus then he should*/
int to_long(int input[]);/*gets the array of input, return true if it have more valeus then he should*/