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
#include <stdio.h>
#include<stdlib.h>
void helper_spiral(int a, int b, int rows, int columns, int** input_array, int* x, int *output_array);
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int range = rows*columns;
	int *output_array = (int*)malloc((range)* sizeof(int));
	int *x = (int*)calloc(1, sizeof(int));
	helper_spiral(0, 0, rows, columns, input_array, x, output_array);
	/*printf("\n");
	for (int i = 0; i < *x; i++)
	printf("%d ", output_array[i]);*/
	return output_array;
}
void helper_spiral(int rIndex, int cIndex, int rows, int columns, int** input_array, int* x, int *output_array)

{
	if (rIndex >= rows || cIndex >= columns)
		return;
	// going right
	for (int i = cIndex; i < columns; ++i){
		output_array[*x] = input_array[rIndex][i];
		(*x)++;
	}
	rIndex++;
	// going down 
	for (int i = rIndex; i < rows; ++i){
		output_array[*x] = input_array[i][columns - 1];
		//printf("%d ",input_array[i][columns - 1]);
		(*x)++;
	}
	columns--;
	// going left 
	if (rIndex < rows)
	{
		for (int i = columns - 1; i >= cIndex; --i){
			output_array[*x] = input_array[rows - 1][i];
			//printf("%d ", input_array[rows - 1][i]);
			(*x)++;
		}
	}
	rows--;
	// going up 
	if (cIndex < columns)
	{
		for (int i = rows - 1; i >= rIndex; --i){
			output_array[*x] = input_array[i][cIndex];
			//printf("%d ", input_array[i][cIndex]);
			(*x)++;
		}
		cIndex++;
	}

	helper_spiral(rIndex, cIndex, rows, columns, input_array, x, output_array);
}