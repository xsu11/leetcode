/*
 * NthDigit.c
 *
 *  Created on: Sep 29, 2016
 *      Author: xinsu
 */

/*
 Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

 Note:
 n is positive and will fit within the range of a 32-bit signed integer (n < 231).

 Example 1:

 Input:
 3

 Output:
 3
 Example 2:

 Input:
 11

 Output:
 0

 Explanation:
 The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
 */

#include <stdio.h>

int findNthDigit(int n) {
	if (n < 10) {
		return n;
	}

	n -= 9;
	long i = 90; // how many numbers at this level
	int order = 2; // how many bits
	long count = 180; // count of total bits
	while ((long) n > count) {
		// if n > count, then count is within the range of int, it can be casted to int savely
		n -= (int) count;
		i *= 10;
		order++;
		count = i * order;
	}

	long num = (i / 9) + (n - 1) / order; // which number
	int offset = n % order; // which bit
	if (offset != 0) {
		offset = order - n % order;
	}

	while (offset-- > 0) {
		num /= 10;
	}

	return num % 10;
}
