/*
 * PowerOfThree5.c
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

bool isPowerOfThree(int n) {
	if (n < 1) {
		return false;
	}

	double x = n;
	while (x >= 3.0) {
		x /= 3.0;
	}

	return x == 1.0;
}

