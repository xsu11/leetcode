/*
 * ImplementStrStr4_Finite_Automata.c
 *
 *  Created on: Sep 03, 2016
 *      Author: xinsu
 *
 * Finite Automata, using a prefix function to compute transition function in O(m * sigma) time
 */

/*
 Implement strStr().

 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <stdio.h>
#include <string.h>

char *getAlphabet(char *s, int length, int *aLen) {
	if (length == 0) {
		return NULL;
	}

	char *alphabet = (char *) calloc(length + 1, sizeof(char));

	int i = 0;
	while (s[i] != '\0') {
		// we can use a hash map to dispose this while and make it O(1)
		int j = 0;
		while (alphabet[j] != '\0' && alphabet[j] != s[i]) {
			j++;
		}

		if (alphabet[j] == '\0') {
			alphabet[j] = s[i];
			*aLen = j + 1;
		}

		i++;
	}

	return alphabet;
}

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

int **computeTransitionFunction(char *pattern, int pLen, char *alphabet,
		int aLen) {
	// first compute prefix function
	int *pi = computePrefixFunction(pattern, pLen);

	// alloc memory for delta
	int **delta = (int **) calloc(pLen + 1, sizeof(int *));
	int i = 0;
	for (i = 0; i < pLen + 1; i++) {
		delta[i] = (int *) calloc(aLen + 1, sizeof(int));
	}

	for (int q = 0; q < pLen + 1; q++) {
		for (i = 0; i < aLen; i++) {
			if (q == pLen || pattern[q] != alphabet[i]) {
				delta[q][i] = delta[pi[q - 1]][i];
			} else {
				delta[q][i] = q + 1;
			}
		}
	}

	return delta;
}

int finiteAutomatonMatcher(char *text, int tLen, char *pattern, int pLen,
		int **delta, char *alphabet, int aLen) {
	int q = 0;

	for (int i = 0; i < tLen; i++) {
		// find the pos of text[i] in the alphabet
		// we can use a hash map to dispose this while and make it O(1)
		int j = 0;
		while (j < aLen && alphabet[j] != text[i]) {
			j++;
		}

		// get next state from transition function
		q = delta[q][j];

		// if a result is found, return the index of the first matching char
		if (q == pLen) {
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

	// get the alphabet of the pattern
	int aLen = 0;
	char *alphabet = getAlphabet(needle, nLen, &aLen);

	// compute transition function
	int **delta = computeTransitionFunction(needle, nLen, alphabet, aLen);

	// start the matcher
	int result = finiteAutomatonMatcher(haystack, hLen, needle, nLen, delta,
			alphabet, aLen);

	// free memory
	free(alphabet);

	for (int i = 0; i < nLen + 1; i++) {
		free(delta[i]);
	}
	free(delta);

	return result;
}
