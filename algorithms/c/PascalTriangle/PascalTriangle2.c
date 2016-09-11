/*
 * PascalTriangle.c
 *
 *  Created on: Sep 10, 2016
 *      Author: xinsu
 *
 * Iteration
 */

/*
 Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return

 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 */

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int **generate(int numRows, int **columnSizes) {
	if (numRows <= 0) {
		*columnSizes = NULL;
		return NULL;
	}

	// alloc memory and set initial value for result and columnSizes
	int **result = (int **) calloc(numRows, sizeof(int *));
	result[0] = (int *) calloc(1, sizeof(int));
	result[0][0] = 1;

	*columnSizes = (int *) calloc(numRows, sizeof(int));
	int i = 0;
	for (i = 0; i < numRows; i++) {
		columnSizes[0][i] = i + 1;
	}

	// create Pascal Triangle line by line
	for (i = 1; i < numRows; i++) {
		result[i] = (int *) calloc(columnSizes[0][i], sizeof(int));
		result[i][0] = 1;
		int j = 1;
		for (j = 1; j < columnSizes[0][i] - 1; j++) {
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
		result[i][j] = 1;
	}

	return result;
}
