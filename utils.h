#define N 3 /*matrix length*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

void printmatrix(int matrix[][N]);
int magic_check(int matrix[][N]); 
int rows_check(int matrix[][N], int magic);
int coloums_check(int matrix[][N], int magic);
int diagonals_check(int matrix[][N], int magic);
int is_valid(int matrix[][N]);
int to_short(int input[]);
int to_long(int input[]);