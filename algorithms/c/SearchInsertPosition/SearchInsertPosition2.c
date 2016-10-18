/*
 * SearchInsertPosition2.c
 *
 *  Created on: Oct 18, 2016
 *      Author: xinsu
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

int bsearchInsert(int* nums, int l, int r, int target) {
	if (l > r) {
		return l;
	}

	int mid = l + (r - l) / 2;

	if (nums[mid] < target) {
		return bsearchInsert(nums, mid + 1, r, target);
	} else if (target < nums[mid]) {
		return bsearchInsert(nums, l, mid - 1, target);
	} else {
		return mid;
	}
}

int searchInsert(int* nums, int numsSize, int target) {
	if (nums == NULL || numsSize < 0) {
		return 0;
	}

	return bsearchInsert(nums, 0, numsSize - 1, target);
}
