/*
 * PascalTriangleII2.c
 *
 *  Created on: Sep 10, 2016
 *      Author: xinsu
 *
 * Iteration: Re-use the memory space.
 */

/*
 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].

 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int *getRow(int rowIndex, int *returnSize) {
	if (rowIndex < 0) {
		*returnSize = 0;
		return NULL;
	}

	// set the returnSize and alloc memory for the entire array
	*returnSize = rowIndex + 1;
	int *result = (int *) calloc(*returnSize, sizeof(int));

	// start from the 0-th row and get to the target
	int i = 0;
	for (i = 0; i < *returnSize; i++) {
		// first set the additional element of the new row to 1
		result[i] = 1;

		// then get all other elements from previous row, backward
		int j = i - 1;
		for (; j > 0; j--) {
			result[j] = result[j] + result[j - 1];
		}
	}

	return result;
}
