/*
 * Pow3.c
 *
 *  Created on: Oct 21, 2016
 *      Author: xinsu
 */

/*
 Implement pow(x, n).
 */

#include <stdio.h>

double myPow(double x, int n) {
	if (x == 0.0) {
		return 0.0;
	} else if (x == 1.0) {
		return x;
	} else if (x == -1.0) {
		return ((n & 1) == 0) ? 1.0 : -1.0;
	}

	if (n == 0) {
		return 1.0;
	}

	int backupN = n;
	double backupX = x;

	if (n < 0) {
		x = 1 / x;
		n = -(n + 1);
	}

	double result = 1.0;
	while (n > 0) {
		if ((n & 1) != 0) {
			result *= x;
		}

		x *= x;
		n /= 2;
	}

	if (backupN < 0) {
		result /= backupX;
	}

	return result;
}
