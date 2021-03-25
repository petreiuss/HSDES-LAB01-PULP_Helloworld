/* 
 * Copyright (C) 2020 University of Bologna
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 */

#include "pmsis.h"

#define COORDINATES 1
#define N 10
int matrix[N*N];

// write your functions here
void init_matrix(int * mat, int size)
{
	for(int i=0; i<size*size; i++){
		mat[i] = i;
	}
}

int matop(int * mat, int size){
	int sum_diag = 0;
	int ret_value = 0;
	for(int i=0; i<size; i++){
		sum_diag+=mat[i*size+i];
	}
	if(sum_diag & 0x1) // odd
	{
		//return the minimum value
		ret_value = mat[0];
		for(int i=1; i<size*size; i++){
			if(mat[i]<ret_value)	ret_value = mat[i];
		}
	}
	else
	{
		//return the maximum value
		ret_value = mat[0];
		for(int i=1; i<size*size; i++){
			if(mat[i]>ret_value)	ret_value = mat[i];
		}
	}
	return ret_value;

}

void matop_with_coordinates(int * mat, int size, int * x, int * y){
	int sum_diag = 0;
	int ret_value;
	for(int i=0; i<size; i++){
		sum_diag+=mat[i*size+i];
	}

	// initialize return values
	ret_value = mat[0];
	*x = 0;
	*y = 0;

	// computes min/max
	if(sum_diag & 0x1) // odd
	{
		for(int i=0; i<size; i++){
			for (int j=0; j<size; j++){
				if(mat[i*size+j]<ret_value){
					ret_value = mat[i*size+j];
					*x = i;
					*y = j;
				}	
			}
		}
	}
	else
	{
		//compute the maximum value
		ret_value = mat[0];
		for(int i=0; i<size; i++){
			for (int j=0; j<size; j++){
				if(mat[i*size+j] > ret_value){
					ret_value = mat[i*size+j];
					*x = i;
					*y = j;
				}	
			}
		}
	}
}

int main()
{
	int x,y;
	init_matrix(matrix, N);
	printf("This is the input matrix:\n");
	for(int i=0; i<N; i++){
		for(int j=0;j<N;j++){
			printf("%d ", matrix[i*N+j]);
		}
		printf("\n");
	}
	int value = matop(matrix, N);

	matop_with_coordinates(matrix, N, &x, &y);

	printf("\n\nThe return value is %d at coordinates [%d, %d]\n", value, x,y);
}