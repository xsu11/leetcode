/*
 * ImplementStrStr3_KMP.c
 *
 *  Created on: Sep 04, 2016
 *      Author: xinsu
 *
 * KPM string matching algorithm
 */

/*
 Implement strStr().

 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <stdio.h>
#include <stdbool.h>

int *computePrefixFunction(char *pattern, int pLen) {
	int *pi = (int *) calloc(pLen, sizeof(int));

	int k = 0;
	for (int q = 1; q < pLen; q++) {
		while (k > 0 && pattern[k] != pattern[q]) {
			k = pi[k - 1];
		}

		if (pattern[k] == pattern[q]) {
			k++;
		}

		pi[q] = k;
	}

	return pi;
}

int kmpMatcher(char *text, int tLen, char *pattern, int pLen, int *pi,
		int *curQ) {
	int q = *curQ;
	for (int i = 0; i < tLen; i++) {
		while (q > 0 && pattern[q] != text[i]) {
			q = pi[q - 1];
		}

		if (pattern[q] == text[i]) {
			q++;
		}

		if (q == pLen) {
			*curQ = pi[q - 1];
			return i + 1 - pLen;
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

	// compute the prefix function
	int *pi = computePrefixFunction(needle, nLen);

	// start the matcher
	int curQ = 0;
	int result = kmpMatcher(haystack, hLen, needle, nLen, pi, &curQ);

	free(pi);

	return result;
}
