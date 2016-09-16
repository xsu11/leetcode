/*
 * NumberOf1Bits1.c
 *
 *  Created on: Sep 16, 2016
 *      Author: xinsu
 *
 * Count by bit.
 */

/*
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has
 (also known as the Hamming weight).

 For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
 so the function should return 3.

 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
	int count = 0;

	for (; n != 0; count++) {
		n &= n - 1;
	}

	return count;
}
