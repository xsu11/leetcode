/*
 * PowerOfThree1.c
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
#include <math.h>
#include <limits.h>

bool isPowerOfThree(int n) {
	if (n < 1) {
		return false;
	}

	int x = (int) pow(3, (int) (log(INT_MAX) / log(3)));
	return !(x % n);
}
