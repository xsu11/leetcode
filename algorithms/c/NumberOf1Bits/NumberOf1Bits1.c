/*
 * NumberOf1Bits1.c
 *
 *  Created on: Sep 16, 2016
 *      Author: xinsu
 *
 * Count by bit.
 * n		: xx...xx100..00 (n has i zeros at the end, 0 <= i <= 32)
 * n - 1	: xx...xx011..11 (n - 1 makes the i zeros to 1s and the i+1 1 to 0)
 * n & (n - 1)	: xx...xx000..00 (n & (n - 1) makes the i + 1 postions at the end to 1s, which change the i + 1 i in n to 0)
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
