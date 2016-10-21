/*
 * Pow2.c
 *
 *  Created on: Oct 21, 2016
 *      Author: xinsu
 */

/*
 Implement pow(x, n).
 */

#include <stdio.h>

double getPow(double x, int n) {
	// base case:
	if (n == 0) {
		return 1.0;
	}

	double half = getPow(x, n / 2);

	double result = 0.0;
	if ((n & 1) != 0) {
		// n is odd
		if (n < 0) {
			// if n < 0, then when calculating n / 2, we omit -1, so we multiply 1 / x
			result = half * half / x;
		} else {
			// if n > 0, then when calculating n / 2, we omit 1, so we multiply x
			result = half * half * x;
		}
	} else {
		result = half * half;
	}

	return result;
}

double myPow(double x, int n) {
	if (x == 0.0) {
		return 0.0;
	} else if (x == 1.0) {
		return x;
	} else if (x == -1.0) {
		return ((n & 1) == 0) ? 1.0 : -1.0;
	}

	return getPow(x, n);
}
