/*
 * PlusOne.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 */

/*
 Given a non-negative number represented as an array of digits, plus one to the number.

 The digits are stored such that the most significant digit is at the head of the list.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int *result;

	// input digit is empty, return 1
	if (digitsSize < 1) {
		result = (int *) calloc(1, sizeof(int));
		result[0] = 1;
		*returnSize = 1;
		return result;
	}

	// find the first digit that is not 9
	int i = digitsSize - 1;
	while (i > -1 && digits[i] == 9) {
		i--;
	}

	if (i == -1) {
		// All positions in digits are 9s. Use resultLong to add 1 to the front of digits and return it.
		result = (int *) calloc(digitsSize + 1, sizeof(int));
		result[0] = 1;
		*returnSize = digitsSize + 1;
	} else {
		// Copy remains from digits to result and return it.
		result = (int *) calloc(digitsSize, sizeof(int));
		result[i] = digits[i] + 1;
		for (i--; i > -1; i--) {
			result[i] = digits[i]; // We can also use memcpy()
		}
		*returnSize = digitsSize;
	}

	return result;
}
