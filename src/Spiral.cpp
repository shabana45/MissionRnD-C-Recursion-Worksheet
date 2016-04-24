/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int i = -1;
void leftup(int a, int b, int rows, int columns, int** input_array, int *output_array, int** x);
void rightdown(int a, int b, int rows, int columns, int** input_array, int *output_array, int** x);
int *spiral(int rows, int columns, int **input_array)
{
	if (*input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	/*int *output_array = (int*)malloc(10 * sizeof(int));
	int **x = (int**)malloc(rows*sizeof(int*));
	for (int i = 0; i < rows; i++)
		x[i] = (int*)malloc(columns*sizeof(int));
	for (int i = 0; i < rows; i++)
	for (int j = 0; j < columns; j++)
		x[i][j] = 0;
	rightdown(0, 0, rows, columns, input_array, output_array, x);
	//for (int j = 0; j < i; j++)
		//printf("%d ", output_array[j]);
	return output_array;*/
}
void rightdown(int a, int b, int rows, int columns, int** input_array, int *output_array, int** x)

{
	if (a < 0 || b < 0 || a >= rows || b >= columns)
		return;
	if (x[a][b] != 1){

		//printf("%d ", input_array[a][b]);
		output_array[i++] = input_array[a][b];
	}
	x[a][b] = 1;
	rightdown(a, b + 1, rows, columns, input_array, output_array, x);
	rightdown(a + 1, columns - 1, rows, columns, input_array, output_array, x);
	leftup(a, columns - 1, rows, columns, input_array, output_array, x);
}
void leftup(int a, int b, int rows, int columns, int** input_array, int *output_array, int** x)

{
	if (a < 0 || b < 0 || a >= rows || b >= columns)
		return;
	//printf("%d %d", a, b);
	if (x[a][b] != 1){
		//	printf("%d ", input_array[a][b]);
		output_array[i++] = input_array[a][b];
	}
	x[a][b] = 1;
	leftup(a, b - 1, rows, columns, input_array, output_array, x);
	leftup(a - 1, 0, rows, columns, input_array, output_array, x);
	rightdown(a + 1, b + 1, rows - 1, columns - 1, input_array, output_array, x);
}

