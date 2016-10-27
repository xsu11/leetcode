/*
 * FactorialTrailingZeroes1.c
 *
 *  Created on: Sep 14, 2016
 *      Author: xinsu
 * 
 * Use prime factorization to find how many 2 and 5 n! has.
 * Because the n! must has enought 2s, the problem becomes how manys 5 does it contain.
 */

/*
 Given an integer n, return the number of trailing zeroes in n!.

 Note: Your solution should be in logarithmic time complexity.

 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 */

#include <stdio.h>

int trailingZeroes(int n) {
	int result = 0;

	int num = n;
	while ((num = num / 5) != 0) {
		result += num;
	}

	return result;
}
