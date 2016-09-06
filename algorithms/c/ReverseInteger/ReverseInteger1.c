/*
 * ReverseInteger1.c
 *
 *  Created on: Aug 29, 2016
 *      Author: xinsu
 */

/*
 Reverse digits of an integer.

 Example1: x = 123, return 321
 Example2: x = -123, return -321

 click to show spoilers.

 Have you thought about this?
 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

 Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 Update (2014-11-10):
 Test cases had been added to test the overflow behavior.
 */

#include <stdio.h>
#include <limits.h>
#include <math.h>

int *seperateInt(int x, int length) {
	int *bits = (int *) calloc(length, sizeof(int));
	int i = 0;
	while (x != 0) {
		bits[i++] = x % 10;
		x /= 10;
	}

	return bits;
}

int reverse(int x) {
	// special case
	if (x == INT_MIN || x == 0) {
		return 0;
	}

	// get sign and a absolute value of x
	int sign = x > 0 ? 1 : -1;
	int absX = x * sign; // absolute value of x

	// get length
	int length = log10(absX) + 1;
	int maxLength = log10(INT_MAX) + 1;

	// seperate x to bits
	int *bits = seperateInt(absX, length);

	int i = 0;

	// check if the reverse will cause overflow
	if (length == maxLength) {
		// seperate INT_MAX to bits
		int *maxBits = seperateInt(INT_MAX, maxLength);
		i = 0;
		while (i < length && bits[i] >= maxBits[length - 1 - i]) {
			if (bits[i] > maxBits[length - 1 - i]) {
				free(bits);
				free(maxBits);
				return 0;
			} else {
				i++;
			}
		}
		free(maxBits);
	}

	// When code comes here, there is no overflow.
	int result = 0;
	for (i = 0; i < length; i++) {
		result += bits[length - 1 - i] * pow(10, i);
	}
	result *= sign;

	free(bits);
	return result;
}
