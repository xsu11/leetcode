/*
 * PowerOfThree4.c
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

int thr[] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147,
		531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489,
		1162261467 };
int cp(const void*a, const void*b) {
	return *(int*) a - *(int*) b;
}
bool isPowerOfThree(int n) {
	return bsearch(&n, thr, 20, sizeof(int), cp);
}
