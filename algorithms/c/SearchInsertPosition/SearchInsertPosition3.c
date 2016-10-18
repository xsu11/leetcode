/*
 * SearchInsertPosition3.c
 *
 *  Created on: Oct 18, 2016
 *      Author: xinsu
 *
 * Iteration
 */

/*
 Given a sorted array and a target value, return the index if the target is found.
 If not, return the index where it would be if it were inserted in order.

 You may assume no duplicates in the array.

 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
 */

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
	if (nums == NULL || numsSize < 0) {
		return 0;
	}

	int l = 0;
	int r = numsSize - 1;

	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] < target) {
			l = mid + 1;
		} else if (target < nums[mid]) {
			r = mid - 1;
		} else {
			return mid;
		}
	}

	return l;
}
