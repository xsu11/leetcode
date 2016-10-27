/*
 * PascalTriangleII1.c
 *
 *  Created on: Sep 10, 2016
 *      Author: xinsu
 *
 * Mathematical way:
 * The 0-th row of Pascal's triangle is 1, that is the coefficient of (a + b)^0 = 1.
 * The k-th (k >= 1) row of the Pascal's triangle is the coefficients array of (a + b)^k.
 * The i-th (0 <= i <= k + 1) coefficient is C_k^i (combination of choosing i from k).
 * C_k^0 = 1
 * C_k^i = C_k^(i-1) * (k + 1 - i) / i
 * C_k^i = C_k^(k-i) (i >= 1)
 *
 * Warning: When calculating C_k^i using the formular above, the multiplication may overflow,
 * therefore, cast the result to long (or long long) first, and then after the division cast it bact to int.
 * This is actually not the best way to do this, for the int and the casted data type may have the same length of bits.
 */

/*
 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].

 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int *getRow(int rowIndex, int *returnSize) {
	if (rowIndex < 0) {
		*returnSize = 0;
		return NULL;
	}

	*returnSize = rowIndex + 1;
	int *result = (int *) calloc(*returnSize, sizeof(int));

	result[0] = 1;
	for (int i = 1, j = rowIndex - 1; i <= j; i++, j--) {
		result[i] = (long long) result[i - 1] * (*returnSize - i) / i;
		result[j] = result[i];
	}
	result[rowIndex] = 1;

	return result;
}
