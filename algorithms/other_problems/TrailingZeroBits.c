/*
 * TrailingZeroBits.c
 *
 *  Created on: Sep 1, 2016
 *      Author: xinsu
 *
 Write a function to count the
 number of trailing zero bits
 found in a 32 bit unsigned
 value.
 Write fast, efficient code, but
 don’t use table lookups.
 Do not use standard library
 functions or containers in your
 response.
 *
 */
#include <stdio.h>

unsigned TrailingZeroBits(unsigned n) {
	printf("%x\n", n);
	printf("%x\n", -n);
	n = n & (-n);
	printf("%x\n", n);
	unsigned result = 0;
	while (n > 1) {
		result++;
		n >>= 1;
	}
	printf("result = %d\n", result);
	return result;
}

//int main() {
//	unsigned a = 0x0000000;
//	TrailingZeroBits(a);
//}
