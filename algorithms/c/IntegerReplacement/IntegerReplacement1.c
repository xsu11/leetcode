/*
 * IntegerReplacement1.c
 *
 *  Created on: Sep 29, 2016
 *      Author: xinsu
 *
 * This solution returns 32 when n = INT_MAX, therefore it just survives on Leetcode...
 * When n = INT_MAX, the answer should be 33 instead of 32.
 */

/*
 Given a positive integer n and you can do operations as follow:

 If n is even, replace n with n/2.
 If n is odd, you can replace n with either n + 1 or n - 1.
 What is the minimum number of replacements needed for n to become 1?

 Example 1:

 Input:
 8

 Output:
 3

 Explanation:
 8 -> 4 -> 2 -> 1
 Example 2:

 Input:
 7

 Output:
 4

 Explanation:
 7 -> 8 -> 4 -> 2 -> 1
 or
 7 -> 6 -> 3 -> 2 -> 1
 */

#include <stdio.h>
#include <limits.h>

int integerReplacement(int n) {
	if (n < 1) {
		return 0;
	} else if (n < 4) {
		return n - 1;
	}

	int result = (n == INT_MAX) ? 0 : 1;

	if ((n & 1) == 0) {
		result += integerReplacement(n >> 1);
	} else if (n < INT_MAX && ((long) n + 1) % 4 == 0) {
		result += integerReplacement(n + 1);
	} else {
		result += integerReplacement(n - 1);
	}

	return result;
}
