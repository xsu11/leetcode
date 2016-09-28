/*
 * ReverseString2.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 *
 * Reverse string and store result to a new string.
 */

/*
 Write a function that takes a string as input and returns the string reversed.

 Example:
 Given s = "hello", return "olleh".
 */

#include <stdio.h>
#include <string.h>

char* reverseString(char* s) {
	int length = strlen(s);

	if (length <= 1) {
		return s;
	}

	char *result = (char *) calloc(length + 1, sizeof(char));
	for (int i = 0; i < length; i++) {
			result[length - 1 - i] = s[i];
	}

	return result;
}
