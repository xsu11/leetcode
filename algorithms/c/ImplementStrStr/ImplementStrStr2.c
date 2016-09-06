/*
 * ImplementStrStr2.c
 *
 *  Created on: Sep 04, 2016
 *      Author: xinsu
 *
 * Brutal force
 */

/*
 Implement strStr().

 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <stdio.h>
#include <stdbool.h>

bool equals(char *s, char *t) {
	int i = 0;

	while (t[i] != '\0') {
		if (s[i] != t[i]) {
			return false;
		}
		i++;
	}

	return true;
}

int strStr(char* haystack, char* needle) {
	if (needle[0] == '\0') {
		return 0;
	} else if (haystack[0] == '\0') {
		return -1;
	}

	int hLength = strlen(haystack);
	int nLength = strlen(needle);

	if (hLength < nLength) {
		return -1;
	}

	int i = 0;

	for (i = 0; i < hLength + 1 - nLength; i++) {
		if (equals(haystack + i, needle)) {
			return i;
		}
	}
	return -1;
}
