/*
 * MaximumSubarray2.c
 *
 *  Created on: Oct 21, 2016
 *      Author: xinsu
 * 
 * Divide and conquer
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
#include <stdbool.h>

int getMaxSubArray(int *nums, int numsSize, int l, int r) {
	// base case
	if (l > r) {
		return 0;
	} else if (l == r) {
		return nums[l];
	}

	int m = l + (r - l) / 2;

	int lM = nums[m];
	int sum = nums[m];
	for (int i = m - 1; i > l - 1; i--) {
		sum += nums[i];
		if (lM < sum) {
			lM = sum;
		}

	}

	int rM = nums[m + 1];
	sum = nums[m + 1];
	for (int i = m + 2; i < r + 1; i++) {
		sum += nums[i];
		if (rM < sum) {
			rM = sum;
		}
	}

	int crossMax = lM + rM;
	int lMax = getMaxSubArray(nums, numsSize, l, m);
	int rMax = getMaxSubArray(nums, numsSize, m + 1, r);

	int result = (lMax > rMax) ? lMax : rMax;
	if (result < crossMax) {
		result = crossMax;
	}

	return result;
}

int maxSubArray(int *nums, int numsSize) {
	if (nums == NULL || numsSize < 1) {
		return NULL;
	} else if (numsSize == 1) {
		return nums[0];
	}

	return getMaxSubArray(nums, numsSize, 0, numsSize - 1);
}
