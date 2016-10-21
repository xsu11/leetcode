/*
 * Pow1.c
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
	} else if (n == 2) {
		// The rason we add n == 2 as the base case is:
		// later when we call the recursion we cut n into half and then use 2 as n to calculate the square
		// this makes n = 2 is very offen to be the input parameter.

		// Of course we can cut n into third instead of half, which makes the code longer but the runtime stays almost the same,
		// because we do the mulplication operation the same time.
		// However it could have smaller stack depth.
		return x * x;
	}

	if (n < 0) {
		// When we flip n from negative to positive, it may encounter overflow when n = INT_MIN.
		// Because INT_MIN and INT_MAX has only 1 difference in abs vale, so we make n to n + 1 before filping it
		// But remember to multiply one more 1 / x.
		return getPow(1.0 / x, -(n + 1)) / x;
	} else {
		return getPow(getPow(x, n / 2), 2) * (((n & 1) == 0) ? 1.0 : x);
	}
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
