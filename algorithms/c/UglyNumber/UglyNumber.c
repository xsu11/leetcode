/*
 * UglyNumber.c
 *
 *  Created on: Sep 26, 2016
 *      Author: xinsu
 */

/*
 Write a program to check whether a given number is an ugly number.

 Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

 Note that 1 is typically treated as an ugly number.

 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>

bool isUgly(int num) {
	// The condition of "num != 0" has to be added, for when num = 0 the while loop is infinite.
	// It is more convenience we not only check 2, 3, 5 but check 4 as well.
	// After check 2, when checking 4 it will not go into the while.
	for (int i = 2; i < 6 && num != 0; i++) {
		while (num % i == 0) {
			num /= i;
		}
	}

	return num == 1;
}
