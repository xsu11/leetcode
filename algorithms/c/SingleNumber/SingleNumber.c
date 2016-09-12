/*
 * SingleNumber.c
 *
 *  Created on: Sep 12, 2016
 *      Author: xinsu
 */

/*
 Given an array of integers, every element appears twice except for one. Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
	if (nums == NULL || numsSize <= 0 || numsSize % 2 == 0) {
		return 0;
	}

	int result = nums[0];
	int i = 1;
	for (i = 1; i < numsSize; i++) {
		result ^= nums[i];
	}

	return result;
}
