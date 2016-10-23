/*
 * MaximumSubarray1.c
 *
 *  Created on: Oct 21, 2016
 *      Author: xinsu
 */

/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

 For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 the contiguous subarray [4,-1,2,1] has the largest sum = 6.

 click to show more practice.

 More practice:
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <stdio.h>

int maxSubArray(int *nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		return NULL;
	} else if (numsSize == 1) {
		return nums[0];
	}

	int maxEndingHere = nums[0];
	int maxSoFar = nums[0];

	for (int i = 1; i < numsSize; i++) {
		maxEndingHere = (maxEndingHere < 0) ? nums[i] : nums[i] + maxEndingHere;

		if (maxSoFar < maxEndingHere) {
			maxSoFar = maxEndingHere;
		}
	}

	return maxSoFar;
}
