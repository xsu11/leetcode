/*
 * CountAndSay2.c
 *
 *  Created on: Sep 05, 2016
 *      Author: xinsu
 *
 * Tail recursion
 *
 */

/*
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.

 Note: The sequence of integers will be represented as a string.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *countAndSay(int n) {
	// base case
	if (n <= 1) {
		char *r = (char *) calloc(2, sizeof(char));
		r[0] = '1';
		return r;
	}

	// do tail recursion
	char *s = countAndSay(n - 1);

	int length = strlen(s);
	char *result = (char *) calloc(length * 2 + 1, sizeof(char));

	// get new string
	int i = 0;
	int j = 0;
	for (i = 0; i < length; i++) {
		// If the code comes into the for (coming here), then it means it start counting a new number.
		// The count is at least 1.
		int count = 1;
		while (s[i] == s[i + 1]) {
			count++;
			i++;
		}

		// When code comes here, it means s[i] != s[i + 1]. Now save count and number to result string.
		result[j++] = count + '0';
		result[j++] = s[i];
	}
	// set the end '\0'
	result[j] = '\0';

	free(s);
	return result;
}
