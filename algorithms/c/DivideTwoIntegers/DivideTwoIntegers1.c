/*
 * DivideTwoIntegers1.c
 *
 *  Created on: Oct 17, 2016
 *      Author: xinsu
 *
 * Math solution:
 *
 * Let x be the absolute value of dividend, y the absolute value of divisor.
 * Let result = sum(a_i * 2^i) (a = {0, 1}, i = 0..31)
 * 			  = sum(a_i << i) (a = {0, 1}, i = 0..31)
 * The goal is to get a_i (i = 0..31)
 *
 * First we calculate a_31:
 * We have
 *
 * 					x / y  =  result
 * 			   y * result  =  x
 * 		y * sum(a_i << i)  =  x (a = {0, 1}, i = 0..31)							(1)
 *
 * Divide 2^31 (that is right shift 31 bits) for both sides, we have:
 *
 * 		y * sum(a_i >> (31 - i))  =  x >> 31 (a = {0, 1}, i = 0..31)
 *
 * Because a_i = {0, 1}, then for all 31 - i > 0, that is i < 31, a_i >> (31 - i) = 0. Therefore we have:
 *
 * 		y * a_31  =  x >> 31
 * 			a_31  =  (x >> 31) / y
 *
 * If x >> 31 >= y, we have a_31 = 1, we set the 31st bit of the result as 1,
 * else, we have a_31 = 0, we don't need to do anything to the result.
 *
 * After we get a_31, next we get a_30:
 * From equation (1), we subtract y * (a_31 << 31) from both sides:
 *
 * 		y * sum(a_i << i)  =  x - y * (a_31 << 31) (a = {0, 1}, i = 0..30)
 *
 * Then we just redo the entire process to get a_30.
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

	int result = 0;

	bool neg = dividend < 0 ^ divisor < 0;
	unsigned int uDividend = (dividend > 0) ? dividend : ~(dividend - 1);
	unsigned int uDivisor = (divisor > 0) ? divisor : ~(divisor - 1);

	if (uDividend < uDivisor) {
		return 0;
	}

	int bitCount = sizeof(int) << 3;
	for (int i = bitCount - 1; i > -1; i--) {
		if ((uDividend >> i) >= uDivisor) {
			// a_i = 1, set result's i-th bit to 1
			result |= (1 << i);

			// update uDividend
			uDividend -= (uDivisor << i);
		}
		// else, a_i = 0, there is no need to set result or change uDividend
	}

	// the process above makes sure the result won't overflow
	if (neg == true) {
		result = (~result) + 1;
	}

	return result;
}
