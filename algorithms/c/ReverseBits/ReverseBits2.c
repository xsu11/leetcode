/*
 * ReverseBits2.c
 *
 *  Created on: Sep 15, 2016
 *      Author: xinsu
 *
 * Lookup table.
 */

/*
 Reverse bits of a given 32 bits unsigned integer.

 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
 return 964176192 (represented in binary as 00111001011110000010100101000000).

 Follow up:
 If this function is called many times, how would you optimize it?

 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
	int lookup[] = { 0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe, 0x1, 0x9, 0x5, 0xd,
			0x3, 0xb, 0x7, 0xf };

	int result = 0;
	int i = 0;
	for (i = 0; i < 8; i++) {
		// left shift to get space to store the result
		result = (result << 4) | lookup[0xf & (n >> (i << 2))];
	}

	return result;
}
