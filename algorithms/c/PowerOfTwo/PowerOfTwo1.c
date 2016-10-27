/*
 * PowerOfTwo1.c
 *
 *  Created on: Sep 20, 2016
 *      Author: xinsu
 *
 * n & (n - 1) changes the rightmost 1 to 0.
 * n:           x...x1000...000
 * n - 1:       x...x0111...111
 * n & (n - 1): x...x0000...000
 */

/*
 Given an integer, write a function to determine if it is a power of two.

 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
	return n > 0 && (n &= n - 1) == 0;
}
