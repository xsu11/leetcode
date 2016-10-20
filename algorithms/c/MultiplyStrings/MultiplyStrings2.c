/*
 * MultiplyStrings2.c
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
	char *result = (char *) calloc(length + 1, sizeof(char));

	int carry = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < length - 1; i++) {
		int sum = carry;

		// we choose to calculate the range of num1
		// of course num1 could be either short number or long number
		// j is the reversed index of num1, that is, the normal index in num1 is len1 - 1 - j

		// begin and end are both reversed indices of num1,
		// begin is the lower bound of j, and end is the strict upper bound of j,
		// that is begin <= j < end
		int begin = 0; // the lowest boundry of j
		int end = len1; // the highest boundry of j

		if (len2 - 1 < i) {
			// i is out of num2, then j starts from some further pos in num1
			// now the entire num2 is in use
			// the reversed last pos in num2 (len2 - 1) plus the reversed first pos (begin) in num1 should be equal to i
			begin = i - len2 + 1; // <= len2 - 1 + begin = i
		} // else i is in num2
		  // if i is in num1, then j starts from 0 to some pos within num1
		  // else if i is not in num1, then j traverses the entire num1, therefore it starts from 0 as well
		  // begin = 0;

		if (len1 - 1 >= i) {
			// i is in num1, j won't go to the end of num1, it will end at the next pos of i (reversed)
			end = i + 1;
		} // else i is out of num1, j will end at the end of num1, that is len1 (reversed)
		  // end = len1;

		for (j = begin; j < end; j++) {
			// after we decide the boundry of j in num1, we've made sure there is a relatively legal index in num2

			// the normal index x of num1 is from j
			// j + x = len1 - 1
			//	   x = len1 - 1 - j

			// the normal index y of num2 is based on num1's reveresed index j and the i-th lower pos in result
			// j + (len2 - 1 - y) = i
			//				    y = len2 - 1 - i + j

			sum += (num1[len1 - 1 - j] - '0') * (num2[len2 - 1 - i + j] - '0');
		}

		// store the i-th lower pos in result, but in a reversed sequence
		result[i] = (sum % 10) + '0';
		carry = sum / 10;
	}

	if (carry > 0) {
		result[i++] = carry + '0';
	}

	// reverse the result array to get the normal sequence of numbers
	for (j = 0; j < i / 2; j++) {
		char t = result[j];
		result[j] = result[i - 1 - j];
		result[i - 1 - j] = t;
	}

	return result;
}
