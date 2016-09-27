/*
 * MoveZeroes.c
 *
 *  Created on: Sep 26, 2016
 *      Author: xinsu
 *
 * Move all non-zero elements to the front
 */

/*
 Given an array nums, write a function to move all 0's to the end of it while maintaining the
 relative order of the non-zero elements.

 For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

 Note:
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.

 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <stdio.h>

void moveZeroes(int *nums, int numsSize) {
	int nonZeroIdx = 0;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] != 0) {
			nums[nonZeroIdx++] = nums[i];
		}
	}

	for (; nonZeroIdx < numsSize; nonZeroIdx++) {
		nums[nonZeroIdx] = 0;
	}
}
