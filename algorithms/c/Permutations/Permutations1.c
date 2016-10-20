/*
 * Permutations1.c
 *
 *  Created on: Oct 20, 2016
 *      Author: xinsu
 */

/*
 Given a collection of distinct numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
 ]
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

void getPermute(int *nums, int numsSize, int startPos, int **results, int *row) {
	// base case
	int i = 0;
	if (startPos == numsSize) {
		// store nums to the row-th in results
		for (i = 0; i < numsSize; i++) {
			results[*row][i] = nums[i];
		}
		(*row)++;

		return;
	}

	// here: startPos < numsSize, that is, startPos is in the legal range
	getPermute(nums, numsSize, startPos + 1, results, row);

	int t = nums[startPos];
	for (i = startPos + 1; i < numsSize; i++) {
		// swap i-th element with startPos-th element
		nums[startPos] = nums[i];
		nums[i] = t;

		// do recursion
		getPermute(nums, numsSize, startPos + 1, results, row);

		// swap back
		nums[i] = nums[startPos];
		nums[startPos] = t;
	}
}

int **permute(int *nums, int numsSize, int *returnSize) {
	if (nums == NULL || numsSize < 1) {
		return NULL;
	}

	// get returnSize: returnSize = numsSize!
	int i = 2;
	for (*returnSize = 1; i < numsSize + 1; i++) {
		*returnSize *= i;
	}

	// alloc memory for result array
	int **results = (int **) calloc(*returnSize, sizeof(int *));
	for (i = 0; i < *returnSize; i++) {
		results[i] = (int *) calloc(numsSize, sizeof(int));
	}

	int row = 0;
	getPermute(nums, numsSize, 0, results, &row);

	return results;
}
