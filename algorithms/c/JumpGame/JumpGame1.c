/*
 * JumpGame1.c
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

bool jumpForward(int *nums, int numsSize, int pos) {
	// base case
	if (pos == numsSize - 1) {
		return true;
	}

	int nextPos = (pos + nums[pos] < numsSize) ? pos + nums[pos] : numsSize - 1;

	for (int i = nextPos; i > pos; i--) {
		if (jumpForward(nums, numsSize, i) == true) {
			return true;
		}
	}

	return false;
}

bool canJump(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		return false;
	}

	return jumpForward(nums, numsSize, 0);
}
