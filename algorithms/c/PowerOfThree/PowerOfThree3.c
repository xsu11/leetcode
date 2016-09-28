/*
 * PowerOfThree3.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 */

/*
 Given an integer, write a function to determine if it is a power of three.

 Follow up:
 Could you do it without using any loop / recursion?

 Credits:
 Special thanks to @dietpepsi for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPowerOfThree(int n) {
	if (n < 1) {
		return false;
	}

	unsigned int x = 1;
	while (x < INT_MAX) {
		x *= 3;
	}

	return !(x % n);
}
