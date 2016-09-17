/*
 * HouseRobber1.c
 *
 *  Created on: Sep 16, 2016
 *      Author: xinsu
 *
 * Recursion.
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
	if (nums == NULL || numsSize < 1) {
		return 0;
	} else if (numsSize == 1) {
		return nums[0];
	}

	int prev = rob(nums, numsSize - 1);
	int current = rob(nums, numsSize - 2) + nums[numsSize - 1];

	return prev > current ? prev : current;
}
