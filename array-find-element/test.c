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

#define N 50 // matrix size
int array[N];

void init_array(int * A_ar, int size)
{
	for(int i=0;i<size;i++) 
		A_ar[i] = i;
}

// ret
int find_element(int * A_ar, int size, int element){
	int find = -1;
	for(int i=0;i<size;i++){
		if(A_ar[i]==element){
			find = i;
		}
	}
	return find;
}

int main()
{
	int element_to_find = 10;
    init_array(array, N);
    int found = find_element(array, N, element_to_find);
    if (found == -1)
    	printf("Element not found\n");
    else
    	printf("Element %d found at position %d\n", element_to_find, found);
}