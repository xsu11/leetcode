/*
 * ImplementStrStr2_Finite_Automata.c
 *
 *  Created on: Sep 03, 2016
 *      Author: xinsu
 *
 * Finite Automata, using a naive way to compute the transition function in O(m^3 * sigma) time
 */

/*
 Implement strStr().

 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool suffixEquals(char *t, int tLen, char *p, int pLen) {
	int i = 0;
	int j = tLen - pLen;
	while (i < pLen) {
		if (t[j] != p[i]) {
			return false;
		}

		i++;
		j++;
	}

	return true;
}

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

int **computeTransitionFunction(char *pattern, int pLen, char *alphabet,
		int aLen) {
	// alloc memory for delta
	int **delta = (int **) calloc(pLen + 1, sizeof(int *));
	int i = 0;
	for (i = 0; i < pLen + 1; i++) {
		delta[i] = (int *) calloc(aLen + 1, sizeof(int));
	}

	// make a copy of the pattern to use when comparing P_k to P_q
	// this copy is used to form P_q + alphabet[i]
	char *pat = (char *) calloc(pLen + 1, sizeof(char));
	strcpy(pat, pattern);

	for (int q = 0; q < pLen + 1; q++) {
		for (i = 0; i < aLen; i++) {
			// set k: k = min(pLen, q + 1)
			int k = q + 1;
			if (k > pLen) {
				k = pLen;
			}

			// start the comparison process
			bool matched = false;
			while (!matched) {
				// change the q-th char in pat to current char in alphabet, that is alphabet[i]
				// but before do this, backup pat[q] first
				char t = pat[q];
				pat[q] = alphabet[i];

				if (suffixEquals(pat, q + 1, pattern, k)) {
					matched = true;
				} else {
					k--;
				}

				// after comparison, change it back
				pat[q] = t;
			}

			// after the longest suffix of P_q that equals to P_k is found, set k's value to delta
			delta[q][i] = k;
		}
	}

	free(pat);

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
