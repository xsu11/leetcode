/*
 * FactorialTrailingZeroes2.c
 *
 *  Created on: Sep 14, 2016
 *      Author: xinsu
 *
 * Recursion.
 */

/*
 Given an integer n, return the number of trailing zeroes in n!.

 Note: Your solution should be in logarithmic time complexity.

 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 */

#include <stdio.h>

int trailingZeroes(int n) {
	if (n <= 0) {
		return 0;
	}

	int num = n / 5;
	return num + trailingZeroes(num);
}
