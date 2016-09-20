/*
 * CountDuplicateII.c
 *
 *  Created on: Sep 20, 2016
 *      Author: xinsu
 *
 * Brutal force.
 * It can be solved by using hash map.
 * Or sort the array and record the original index at the same time,
 */

/*
 Given an array of integers and an integer k,
 find out whether there are two distinct indices i and j in the array such that
 nums[i] = nums[j] and the difference between i and j is at most k (|i - j| <= k).
 */

#include <stdio.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
	if (nums == NULL || numsSize < 2 || k < 1) {
		return false;
	}

	int i = 0;
	for (i = 0; i < numsSize - 1; i++) {
		int up = i + k + 1 < numsSize ? i + k + 1 : numsSize;
		int j = i + 1;
		for (; j < up; j++) {
			if (nums[j] == nums[i]) {
				return true;
			}
		}
	}

	return false;
}
