/*
 * NumberOf1Bits3.c
 *
 *  Created on: Sep 16, 2016
 *      Author: xinsu
 *
 * 17 arithmetic operations.
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
	uint32_t m1 = 0x55555555; // 0101 0101 0101 0101 0101 0101 0101 0101
	uint32_t m2 = 0x33333333; // 0011 0011 0011 0011 0011 0011 0011 0011
	uint32_t m4 = 0x0f0f0f0f; // 0000 1111 0000 1111 0000 1111 0000 1111
	uint32_t m8 = 0x00ff00ff; // 0000 0000 1111 1111 0000 0000 1111 1111
	uint32_t m16 = 0x0000ffff; // 0000 0000 0000 0000 1111 1111 1111 1111

	uint32_t x = n;

	x -= (x >> 1) & m1; // put count of each 2 bits into those 2 bits
	x = (x & m2) + ((x >> 2) & m2); // put count of each 4 bits into those 4 bits
	x = (x + (x >> 4)) & m4; // put count of each 8 bits into those 8 bits
	x += x >> 8; // put count of each 16 bits into their lowest 8 bits, without clear higher bits
	x += x >> 16; // put count of each 32 bits into their lowest 8 bits, without clear higher bits

	// Only retrieve the lowest 6 bits, for the result is at most 32 which can be represented in 6 bits.
	return x & 0x3f;
}
