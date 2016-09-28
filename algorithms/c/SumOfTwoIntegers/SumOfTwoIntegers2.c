/*
 * SumOfTwoIntegers2.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 */

/*
 Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

 Example:
 Given a = 1 and b = 2, return 3.

 Credits:
 Special thanks to @fujiaozhu for adding this problem and creating all test cases.
 */

#include <stdio.h>

int getSum(int a, int b) {
	while (b != 0) {
		int carry = (a & b) << 1;
		a ^= b;
		b = carry;
	}

	return a;
}
