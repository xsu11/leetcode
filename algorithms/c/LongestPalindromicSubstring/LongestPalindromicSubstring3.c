/*
 * LongestPalindromicSubstring3.c
 *
 *  Created on: Sep 30, 2016
 *      Author: xinsu
 *
 * Same solution as the second one, but shorter code
 */

/*
 Given a string S, find the longest palindromic substring in S.
 You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include <stdio.h>
#include <stdlib.h>

char *longestPalindrome(char *s) {
	if (s == NULL || s[0] == '\0') {
		return NULL;
	}

	// At begining, the first char is palindrome, then the max length = 1
	int maxBegin = 0;
	int maxLength = 0;

	// Check all centers (2n - 1) from index 1.
	// Each time check center at char of index i, and center between char if index i and i - 1.
	int i = 0;
	while (s[i] != '\0') {
		int l = i - 1;
		int r = ++i;

		// set r to the first char right to s[i] that s[r] is not the same as s[i]
		while (s[r] != '\0' && s[r - 1] == s[r]) {
			r++;
		}

		while (l > -1 && s[r] != '\0' && s[l] == s[r]) {
			l--;
			r++;
		}

		int length = r - l - 1;
		if (maxLength < length) {
			maxBegin = l + 1;
			maxLength = length;
		}
	}

	// Calculate the begin index, alloc memory for result and set result.
	char *result = (char *) calloc(maxLength + 1, sizeof(char));
	for (i = 0; i < maxLength; i++) {
		result[i] = s[maxBegin + i];
	}

	return result;
}
