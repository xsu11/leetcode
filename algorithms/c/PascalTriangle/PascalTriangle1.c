/*
 * PascalTriangle.c
 *
 *  Created on: Sep 09, 2016
 *      Author: xinsu
 *
 * Recursion
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

void generateLine(int numRows, int *columnSizes, int **result) {
	int idx = numRows - 1;

	// alloc memory for the the lineNum-th line of result
	result[idx] = (int *) calloc(columnSizes[idx], sizeof(int));

	// base case
	if (numRows == 1) {
		result[0][0] = 1;
		return;
	}

	// do recursion
	generateLine(numRows - 1, columnSizes, result);

	// create the line
	int i = 0;
	result[idx][i] = 1;
	for (i = 1; i < columnSizes[idx] - 1; i++) {
		result[idx][i] = result[idx - 1][i - 1] + result[idx - 1][i];
	}
	result[idx][i] = 1;
}

int **generate(int numRows, int **columnSizes) {
	if (numRows <= 0) {
		*columnSizes = NULL;
		return NULL;
	}

	// Alloc memory for result. Alloc memory and set value for columnSizes.
	int **result = (int **) calloc(numRows, sizeof(int *));
	*columnSizes = (int *) calloc(numRows, sizeof(int));
	int i = 0;
	for (i = 0; i < numRows; i++) {
		columnSizes[0][i] = i + 1;
	}

	// Call the recursive function to finish the work.
	generateLine(numRows, *columnSizes, result);
	return result;
}
