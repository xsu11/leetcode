/*
 * AddBinary.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 */

/*
 Given two binary strings, return their sum (also a binary string).

 For example,
 a = "11"
 b = "1"
 Return "100".
 */

#include <stdio.h>
#include <stdlib.h>

char *addBinary(char* a, char* b) {
	int aLength = strlen(a);
	int bLength = strlen(b);
	int length = (aLength > bLength ? aLength : bLength) + 1;
	char *result = (char *) calloc(length, sizeof(char));

	int carry = 0;
	int i = 0;
	while (i < aLength || i < bLength) {
		int aVal = (i >= aLength) ? 0 : a[aLength - 1 - i] - '0';
		int bVal = (i >= bLength) ? 0 : b[bLength - 1 - i] - '0';
		int sum = aVal + bVal + carry;
		result[length - 2 - i] = sum % 2 + '0';
		carry = sum / 2;
		i++;
	}

	if (carry == 1) {
		char *resultLong = (char *) calloc(length + 1, sizeof(char));
		resultLong[0] = carry + '0';
		for (i = 0; i < length; i++) {
			resultLong[i + 1] = result[i];
		}
		free(result);
		return resultLong;
	}

	return result;
}
