/*
 * JumpGame3.c
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

bool canJump(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		return false;
	}

	// create a dtable
	int *d = (int *) calloc(numsSize, sizeof(int));
	d[numsSize - 1] = GOOD;

	for (int i = numsSize - 2; i > -1; i--) {
		int nextPosBound =
				(i + nums[i] < numsSize) ? i + nums[i] + 1 : numsSize;

		int j = i + 1;
		while (j < nextPosBound && d[j] != GOOD) {
			j++;
		}

		if (j != nextPosBound) {
			d[i] = GOOD;
		}
	}

	return d[0] == GOOD;
}
