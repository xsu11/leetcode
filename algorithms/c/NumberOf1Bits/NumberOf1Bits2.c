/*
 * NumberOf1Bits2.c
 *
 *  Created on: Sep 16, 2016
 *      Author: xinsu
 *
 * Binary count: 24 arithmetic operations (bitwise shit, bitwise and, add)
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

	n = (n & m1) + ((n >> 1) & m1); // put count of each 2 bits into those 2 bits
	n = (n & m2) + ((n >> 2) & m2); // put count of each 4 bits into those 4 bits
	n = (n & m4) + ((n >> 4) & m4); // put count of each 8 bits into those 8 bits
	n = (n & m8) + ((n >> 8) & m8); // put count of each 16 bits into those 16 bits
	n = (n & m16) + ((n >> 16) & m16); // put count of each 32 bits into those 32 bits

	return (int) n;
}
