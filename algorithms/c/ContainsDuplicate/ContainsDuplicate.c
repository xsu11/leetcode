/*
 * CountDuplicate.c
 *
 *  Created on: Sep 19, 2016
 *      Author: xinsu
 *
 * Bitmap: Use an array of 2^(sizeof(int) * 8) length space, and O(n) time.
 * The basic idea is to compare each element to all the rest elements, O(n).
 * Another idea is to sort the array first (O(nlogn)), then check from nums[1] if the element is the same as previous one.
 * A third idea is to use hash set, O(n) time and O(n) space.
 *
 * There is strange point here:
 * when calculating the length = (1 << (sizeof(int) << 3) - 1) / uint32BitLength
 * (this is 2^31 / 32 = 0x80000000 >> 5 = 0x4000000),
 * if I use size_t which is defined as unsigned long, the right shift is arithmetic shift (fill with sign bits),
 * and this gives wrong result (0xfc000000).
 * But if I use unsigned int, it is logical shift (fill with 0-bits), which gives correct result.
 *
 */

/*
 Given an array of integers, find if the array contains any duplicates.
 Your function should return true if any value appears at least twice in the array,
 and it should return false if every element is distinct.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

bool containsDuplicate(int* nums, int numsSize) {
	if (nums == NULL || numsSize < 2) {
		return false;
	}

	unsigned uint32Length = sizeof(uint32_t);
	unsigned uint32BitLength = uint32Length << 3;
	unsigned length = (1 << (sizeof(int) << 3) - 1) / uint32BitLength;

	uint32_t *nonNegBitmap = (uint32_t *) calloc(length, uint32Length);
	uint32_t *negBitmap = (uint32_t *) calloc(length, uint32Length);

	int i = 0;
	for (i = 0; i < numsSize; i++) {
		unsigned n = nums[i];
		uint32_t *bitmap = nonNegBitmap;

		if (nums[i] < 0) {
			n = -nums[i] - 1;
			bitmap = negBitmap;
		}

		int x = n / uint32BitLength;
		int offset = n % uint32BitLength;

		if (getbit(bitmap[x], offset) == 1) {
			return true;
		}
		bitmap[x] = setbit(bitmap[x], offset, 1);
	}

	free(nonNegBitmap);
	free(negBitmap);
	return false;
}
