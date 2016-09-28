/*
 * RangeSumQueryImmutable1.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 *
 * Naive solution
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
	int *nums;
};

/** Initialize your data structure here. */
struct NumArray* NumArrayCreate(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 0) {
		return NULL;
	}

	struct NumArray *numArray = (struct NumArray *) calloc(1,
			sizeof(struct NumArray));
	numArray->nums = (int *) calloc(numsSize, sizeof(int));
	for (int i = 0; i < numsSize; i++) {
		numArray->nums[i] = nums[i];
	}

	return numArray;
}

int sumRange(struct NumArray* numArray, int i, int j) {
	if (numArray == NULL || i > j) {
		return 0;
	}

	int sum = 0;
	for (; i <= j; i++) {
		sum += numArray->nums[i];
	}

	return sum;
}

/** Deallocates memory previously allocated for the data structure. */
void NumArrayFree(struct NumArray* numArray) {
	if (numArray->nums != NULL) {
		free(numArray->nums);
	}
	free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);
