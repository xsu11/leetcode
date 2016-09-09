/*
 * TwoSum.c
 *
 *  Created on: Aug 25, 2016
 *      Author: xinsu
 */

/*
 Given an array of integers, return indices of the two numbers such that they add up to a specific target.

 You may assume that each input would have exactly one solution.

 Example:
 Given nums = [2, 7, 11, 15], target = 9,

 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].
 UPDATE (2016/2/13):
 The return format had been changed to zero-based indices. Please read the above updated description carefully.
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target) {
	int flag = 0;
	int i, j;
	int* result = malloc(2 * sizeof(int));
	for (i = 0; i < numsSize - 1 && flag == 0; i++) {
		for (j = i + 1; j < numsSize && flag == 0; j++) {
			if (nums[i] + nums[j] == target) {
				result[0] = i;
				result[1] = j;
				flag = 1;
			}
		}
	}

	return result;
}
