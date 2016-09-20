/*
 * ReverseBits1.c
 *
 *  Created on: Sep 15, 2016
 *      Author: xinsu
 */

/*
 Reverse bits of a given 32 bits unsigned integer.

 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

 Follow up:
 If this function is called many times, how would you optimize it?

 Related problem: Reverse Integer

 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdint.h>

uint32_t getbit(uint32_t x, int i) {
	return (x >> i) & 1;
}

uint32_t setbit(uint32_t x, int i, uint32_t val) {
	return (x & ~(1 << i)) | (val << i);
}

uint32_t invertbit(uint32_t x, int i) {
	return x ^ (1 << i);
}

uint32_t reverseBits(uint32_t n) {
	uint32_t l = 0;
	uint32_t h = 0;

	int i = 0;
	for (i = 0; i < 16; i++) {
		if ((l = getbit(n, i)) != (h = getbit(n, 31 - i))) {
			n = setbit(n, i, h);
			n = setbit(n, 31 - i, l);
		}
	}

	return n;
}

uint32_t reverseBits2(uint32_t n) {
	int i = 0;
	for (i = 0; i < 16; i++) {
		if (getbit(n, i) != getbit(n, 31 - i)) {
			n = invertbit(n, i);
			n = invertbit(n, 31 - i);
		}
	}

	return n;
}
