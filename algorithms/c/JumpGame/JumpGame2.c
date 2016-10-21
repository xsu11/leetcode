/*
 * JumpGame2.c
 *
 *  Created on: Oct 20, 2016
 *      Author: xinsu
 */

/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Determine if you are able to reach the last index.

 For example:
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdbool.h>

#define GOOD 1
#define BAD -1
#define UNKNOWN 0

bool jumpForward(int *nums, int numsSize, int pos, int *d) {
	// base case
	if (d[pos] != UNKNOWN) {
		return d[pos] == GOOD;
	}

	int nextPosBound =
			(pos + nums[pos] < numsSize) ? pos + nums[pos] + 1 : numsSize;

	for (int i = pos + 1; i < nextPosBound; i++) {
		if (jumpForward(nums, numsSize, i, d) == true) {
			d[pos] = GOOD;
			return true;
		}
	}
	d[pos] = BAD;

	return false;
}

bool canJump(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		return false;
	}

	// create a dtable
	int *d = (int *) calloc(numsSize, sizeof(int));
	d[numsSize - 1] = GOOD;

	bool result = jumpForward(nums, numsSize, 0, d);

	free(d);

	return result;
}
