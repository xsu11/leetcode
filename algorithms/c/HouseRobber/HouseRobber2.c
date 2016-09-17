/*
 * HouseRobber2.c
 *
 *  Created on: Sep 17, 2016
 *      Author: xinsu
 *
 * Top-down with memoization.
 */

/*
 You are a professional robber planning to rob houses along a street.
 Each house has a certain amount of money stashed,
 the only constraint stopping you from robbing each of them is that
 adjacent houses have security system connected and
 it will automatically contact the police if two adjacent houses were broken into on the same night.

 Given a list of non-negative integers representing the amount of money of each house,
 determine the maximum amount of money you can rob tonight without alerting the police.

 Credits:
 Special thanks to @ifanchu for adding this problem and creating all test cases.
 Also thanks to @ts for adding additional test cases.
 */

#include <stdio.h>

int memoizedRob(int *nums, int n, int *r) {
	if (r[n] > 0) {
		return r[n];
	}

	int q = 0;
	if (n > 0) {
		for (int i = 1; i < n + 1; i++) {
			int prev = memoizedRob(nums, i - 1, r);
			int current = memoizedRob(nums, i - 2, r) + nums[i - 1];
			q = prev > current ? prev : current;
		}
	}
	r[n] = q;

	return q;
}

int rob(int* nums, int numsSize) {
	if (nums == NULL || numsSize == 0) {
		return 0;
	}

	int r[numsSize + 1];
	for (int i = 0; i < numsSize + 1; i++) {
		r[i] = -1;
	}

	return memoizedRob(nums, numsSize, &r);
}
