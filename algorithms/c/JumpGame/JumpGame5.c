/*
 * JumpGame5.c
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

bool canJump(int* nums, int numsSize) {
	int lastReachPos = numsSize - 1;

	for (int i = lastReachPos; i > -1; i--) {
		if (i + nums[i] >= lastReachPos) {
			lastReachPos = i;
		}
	}

	return lastReachPos == 0;
}
