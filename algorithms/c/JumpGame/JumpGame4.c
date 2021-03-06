/*
 * JumpGame4.c
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
	int maxReachPos = 0;

	for (int i = 0; i < numsSize && i <= maxReachPos; i++) {
		int nextPos = i + nums[i];
		if (nextPos > maxReachPos) {
			maxReachPos = nextPos;
		}
	}

	return maxReachPos >= numsSize - 1;
}
