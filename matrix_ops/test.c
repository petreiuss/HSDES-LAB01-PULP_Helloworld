/* 
 * Copyright (C) 2020 University of Bologna
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 * Authors: Manuele Rusci, UniBO (manuele.rusci@unibo.it)
 */

#include "pmsis.h"

#define N 3 // matrix size
int matrix[N*N];

//intialize a squared matrix with size number of elements
void init_matrix(int * A_mat, int size)
{
	
	for(int i=0;i<size*size;i++) 
		A_mat[i] = i-66+6;	// this can be changed to whatever pattern

}
/* int max_mat(int * A_mat, int size){
	int max = A_mat[0];
	for(int i=1;i<size*size;i++){
		
		if (max<A_mat[i]){
			max = A_mat[i];
			x = i/size;
			y = i%size;
		}
	}
	return max;
}

int min_mat(int * A_mat,int size){
	int min = A_mat[0];
	for(int i=1;i<size*size;i++){
		
		if (min>A_mat[i]){
			min = A_mat[i];
			x = i/size;
			y = i%size;
		}
	}
	return min,x,y;
} */
int matop(int * A_mat, int size)
{
	int sum = 0;
	int ret_value=0;
	for(int i=0;i<size;i++){
		sum += A_mat[(i*size)+i];
	}
	if (sum%2==0){
		ret_value= A_mat[0];
		for(int i=1;i<size*size;i++){
			
			if (ret_value<A_mat[i]){
				ret_value = A_mat[i];
			}
		}
		
	}
	else{
		ret_value= A_mat[0];
		for(int i=1;i<size*size;i++){
			
			if (ret_value>A_mat[i]){
				ret_value = A_mat[i];
			}
		}
	}
	return ret_value;
}
int matop_coordinates(int *A_mat,int *x, int *y, int size){
	int sum = 0;
	int ret_value=0;
	for(int i=0;i<size;i++){
		sum += A_mat[(i*size)+i];
	}
	if (sum%2==0){
		ret_value= A_mat[0];
		*x=0;
		*y=0;
		for(int i=1;i<size*size;i++){
			
			if (ret_value<A_mat[i]){
				ret_value = A_mat[i];
				*x=i/size;
				*y=i%size;
			}
		}
		
	}
	else{
		ret_value= A_mat[0];
		*x=0;
		*y=0;
		for(int i=1;i<size*size;i++){
			
			if (ret_value>A_mat[i]){
				ret_value = A_mat[i];
				*x=i/size;
				*y=i%size;
			}
		}
	}
	return ret_value;
}
// return the index of the item==element of the array A_ar with size number of elements
int find_element(int * A_ar, int size, int element){
	int find = -1;	// return -1 if the element is not found
	for(int i=0;i<size;i++){
		if(A_ar[i]==element){
			find = i;
		}
	}
	return find;
}

int main()
{
    init_matrix(matrix, N);
	int x,y;
	for(int i =0;i<N;i++){
		for(int j =0; j<N;j++){
			printf("%d \t",matrix[i*N+j]);
		}
		printf("\n");

	}
    // call the find function
    int value = matop_coordinates(matrix,&x,&y ,N);
	
    printf("\n\n result is %d with coordinates [%d,%d]\n", value,x,y);
}