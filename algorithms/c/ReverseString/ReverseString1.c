/*
 * ReverseString1.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 *
 * Reverse string in place.
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

	char t = NULL;
	for (int i = 0; i < length / 2; i++) {
		if (s[i] != s[length - 1 - i]) {
			t = s[i];
			s[i] = s[length - 1 - i];
			s[length - 1 - i] = t;
		}
	}

	return s;
}
