/*
 * RangeSumQueryImmutable3.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 *
 * Using sum map, O(n^2) space.
 */

/*
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

 Example:
 Given nums = [-2, 0, 3, -5, 2, -1]

 sumRange(0, 2) -> 1
 sumRange(2, 5) -> -1
 sumRange(0, 5) -> -3
 Note:
 You may assume that the array does not change.
 There are many calls to sumRange function.
 */

#include <stdio.h>
#include <stdlib.h>

struct NumArray {
	int numsSize;
	int **sums;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 0) {
		return NULL;
	}

	struct NumArray *numArray = (struct NumArray *) calloc(1,
			sizeof(struct NumArray));
	numArray->numsSize = numsSize;
	numArray->sums = (int **) calloc(numsSize, sizeof(int *));
	int i = 0;
	for (i = 0; i < numsSize; i++) {
		numArray->sums[i] = (int *) calloc(numsSize - i, sizeof(int));
	}

	for (i = 0; i < numsSize; i++) {
		numArray->sums[i][0] = nums[i];
		for (int j = 1; j < numsSize - i; j++) {
			numArray->sums[i][j] = numArray->sums[i][j - 1] + nums[i + j];
		}
	}

	return numArray;
}

int sumRange(struct NumArray* numArray, int i, int j) {
	if (numArray == NULL || i > j) {
		return 0;
	}

	return numArray->sums[i][j - i];
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
	if (numArray->sums != NULL) {
		for (int i = 0; i < numArray->numsSize; i++) {
			free(numArray->sums[i]);
		}
		free(numArray->sums);
	}
	free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
