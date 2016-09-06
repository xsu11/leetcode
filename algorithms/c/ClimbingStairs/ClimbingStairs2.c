/*
 * ClimbingStairs.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 *
 * Iterative memoization
 */

/*
 You are climbing a stair case. It takes n steps to reach to the top.

 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
	if (n < 0) {
		return 0;
	} else if (n <= 2) {
		return n;
	}

	int counts[n];
	counts[0] = 1;
	counts[1] = 2;

	int i = 2;
	for (i = 2; i < n; i++) {
		counts[i] = counts[i - 1] + counts[i - 2];
	}

	return counts[n - 1];
}
