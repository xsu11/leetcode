/*
 * ClimbingStairs.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 */

/*
 You are climbing a stair case. It takes n steps to reach to the top.

 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

#include <stdio.h>
#include <stdlib.h>

int countStairs(int *counts, int n) {
	if (n <= 2) {
		return n;
	} else if (counts[n - 1] != 0) {
		return counts[n - 1];
	}

	// memoized recursion
	counts[n - 1] = countStairs(n - 1) + countStairs(n - 2);
	return counts[n - 1];
}

int climbStairs(int n) {
	int *counts = (int *) calloc(n, sizeof(int));
	return countStairs(counts, n);
}
