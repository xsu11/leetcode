/*
 * PowerOfFour1.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 *
 * Assume sizeof(int) = 8 bytes (32 bits)
 */

/*
 Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

 Example:
 Given num = 16, return true. Given num = 5, return false.

 Follow up: Could you solve it without loops/recursion?

 Credits:
 Special thanks to @yukuairoy for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isPowerOfFour(int num) {
	if (num < 1) {
		return false;
	}

	return ((num & (-num)) == num) && ((num & 0x2aaaaaaa) == 0);
}
