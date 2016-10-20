/*
 * MultiplyStrings1.c
 *
 *  Created on: Oct 19, 2016
 *      Author: xinsu
 */

/*
 Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note:
 The numbers can be arbitrarily large and are non-negative.
 Converting the input string to integer is NOT allowed.
 You should NOT use internal library such as BigInteger.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *multiply(char *num1, char *num2) {
	int len1 = strlen(num1);
	int len2 = strlen(num2);

	if (len1 == 0 || len2 == 0 || num1[0] == '0' || num2[0] == '0') {
		char *zero = (char *) calloc(2, sizeof(char));
		*zero = '0';
		return zero;
	}

	int length = len1 + len2;
	int aLength = length - 1;

	// alloc memory for a array and calculate the individual multiplication
	int *a = (int *) calloc(aLength, sizeof(int));

	int i = 0;
	int j = 0;
	for (i = 0; i < len1; i++) {
		int x1 = (int) (num1[len1 - 1 - i] - '0');
		for (j = 0; j < len2; j++) {
			int x2 = (int) (num2[len2 - 1 - j] - '0');
			a[i + j] += x1 * x2;
		}
	}

	// alloc memory for result and set the result
	char *result = (char *) calloc(length + 1, sizeof(char));

	int carry = 0;
	for (i = length, j = 0; j < aLength; j++) {
		int x = a[j] + carry;
		result[--i] = (x % 10) + '0';
		carry = x / 10;
	}

	if (carry > 0) {
		result[--i] = carry + '0';
	}

	// move result to the front of the array
	if (i > 0) {
		for (j = 0; i < length + 1; j++, i++) {
			result[j] = result[i];
		}
	}

	free(a);

	return result;
}
