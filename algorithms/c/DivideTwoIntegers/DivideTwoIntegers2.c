/*
 * DivideTwoIntegers2.c
 *
 *  Created on: Oct 17, 2016
 *      Author: xinsu
 */

/*
 Divide two integers without using multiplication, division and mod operator.

 If it is overflow, return MAX_INT.
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int divide(int dividend, int divisor) {
	if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
		return INT_MAX;
	} else if (dividend == 0) {
		return 0;
	}

	bool neg = dividend < 0 ^ divisor < 0;
	unsigned int uDividend = (dividend > 0) ? dividend : ~(dividend - 1);
	unsigned int uDivisor = (divisor > 0) ? divisor : ~(divisor - 1);

	if (uDividend < uDivisor) {
		return 0;
	}

	int result = 0;

	while (uDividend >= uDivisor) {
		unsigned long d = uDivisor;
		int localResult = 1;
		while (uDividend >= (d << 1)) {
			d <<= 1;
			localResult <<= 1;
		}

		result += localResult;
		uDividend -= d;
	}

	// the process above makes sure the result won't overflow
	if (neg == true) {
		result = (~result) + 1;
	}

	return result;
}
