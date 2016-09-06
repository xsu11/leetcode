/*
 * RemoveDuplicatesFromSortedArray.c
 *
 *  Created on: Sep 03, 2016
 *      Author: xinsu
 */

/*
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place with constant memory.

 For example,
 Given input array nums = [1,1,2],

 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
 It doesn't matter what you leave beyond the new length.
 */

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	int result = 0;

	int i = 0;
	for (i = 0; i < numsSize; i++) {
		if (i == 0 || nums[i] != nums[result - 1]) {
			nums[result++] = nums[i];
		}
	}

	return result;
}
