/*
 * NumberOf1Bits5.c
 *
 *  Created on: Sep 16, 2016
 *      Author: xinsu
 *
 * Lookup table, if the size of memory is allowed.
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

uint32_t wordbits[65536] = { /* list of bits count from 0x0 to 0xffff */};

int hammingWeight(uint32_t n) {
	return (int) (wordbits[n & 0xffff] + wordbits[n >> 16]);
}
