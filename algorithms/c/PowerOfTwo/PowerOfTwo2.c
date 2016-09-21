/*
 * PowerOfTwo2.c
 *
 *  Created on: Sep 20, 2016
 *      Author: xinsu
 *
 * Find the largest integer of power of 2 and mod n.
 */

/*
 Given an integer, write a function to determine if it is a power of two.

 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
	unsigned k = INT_MAX + 1;
	return n > 0 && k % n == 0;
}
