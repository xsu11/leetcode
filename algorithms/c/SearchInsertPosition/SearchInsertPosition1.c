/*
 * SearchInsertPosition1.c
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
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target) {
	if (nums == NULL || numsSize < 0) {
		return 0;
	}

	int result = 0;

	int midIdx = numsSize / 2;
	int *mid = nums + midIdx;

	if (*mid < target) {
		if (midIdx == numsSize - 1) {
			result = numsSize;
		} else if (midIdx < numsSize - 1 && target < *(mid + 1)) {
			result = midIdx + 1;
		} else {
			// *(mid + 1) < target
			result = midIdx + 1
					+ searchInsert(mid + 1, numsSize - 1 - midIdx, target);
		}
	} else if (target < *mid) {
		if (midIdx == 0) {
			result = 0;
		} else if (midIdx > 0 && *(mid - 1) < target) {
			result = midIdx;
		} else {
			// target < *(mid - 1)
			result = searchInsert(nums, midIdx - 1, target);
		}
	} else {
		result = midIdx;
	}

	return result;
}
