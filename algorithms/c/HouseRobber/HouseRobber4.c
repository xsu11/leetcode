/*
 * HouseRobber3.c
 *
 *  Created on: Sep 17, 2016
 *      Author: xinsu
 *
 * Bottom-up method.
 * This method doesn't use an additional array to save the rob solution.
 * And it only uses two additional ints to store previous two largest values to get current value.
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

	int prev = 0;
	int current = nums[0];

	for (int i = 1; i < numsSize; i++) {
		int p = prev + nums[i];
		prev = current;
		current = current > p ? current : p;
	}

	return current;
}
