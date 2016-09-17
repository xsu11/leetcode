/*
 * HouseRobber3.c
 *
 *  Created on: Sep 17, 2016
 *      Author: xinsu
 *
 * Bottom-up method. This method doesn't use an additional array to save the rob solution.
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

int rob(int* nums, int numsSize) {
	if (nums == NULL || numsSize == 0) {
		return 0;
	}

	int r[numsSize + 1];
	r[0] = 0;
	r[1] = nums[0];

	int q = 0;
	for (int j = 2; j <= numsSize; j++) {
		for (int i = 2; i <= j; i++) {
			int prev = r[i - 1];
			int current = r[i - 2] + nums[i - 1];
			q = prev > current ? prev : current;
		}
		r[j] = q;
	}

	return r[numsSize];
}
