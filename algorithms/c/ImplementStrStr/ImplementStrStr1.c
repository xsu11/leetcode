/*
 * ImplementStrStr1.c
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

bool equals(char *t, char *p, int pLen) {
	int i = 0;

	while (i < pLen) {
		if (t[i] != p[i]) {
			return false;
		}
		i++;
	}

	return true;
}

int naiveStringMatcher(char *text, int tLen, char *pattern, int pLen) {
	for (int i = 0; i < tLen - pLen + 1; i++) {
		if (equals(text + i, pattern, pLen)) {
			return i;
		}
	}

	return -1;
}

int strStr(char* haystack, char* needle) {
	if (needle[0] == '\0') {
		return 0;
	} else if (haystack[0] == '\0') {
		return -1;
	}

	int hLen = strlen(haystack);
	int nLen = strlen(needle);

	if (hLen < nLen) {
		return -1;
	}

	return naiveStringMatcher(haystack, hLen, needle, nLen);
}
