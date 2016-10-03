/*
 * LongestPalindromicSubstring2.c
 *
 *  Created on: Sep 30, 2016
 *      Author: xinsu
 *
 * An improved approach which use O(n^2) time but O(1) space
 */

/*
 Given a string S, find the longest palindromic substring in S.
 You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include <stdio.h>
#include <stdlib.h>

int checkPalindrome(char *s, int left, int right) {
	// Set len (this is for use when calculate the final length)
	int len = 0;

	if (left == right) {
		len++;
		left--;
		right++;
	}

	// Calculate the radius
	while (s[right] != '\0' && s[left--] == s[right++]) {
		len += 2;
	}

	return len;
}

char *longestPalindrome(char *s) {
	if (s == NULL || s[0] == '\0') {
		return NULL;
	}

	// At begining, the first char is palindrome, then the max length = 1
	int maxCenter = 0;
	int maxLength = 1;

	// Check all centers (2n - 1) from index 1.
	// Each time check center at char of index i, and center between char if index i and i - 1.
	int i = 1;
	while (s[i] != '\0') {
		int len = checkPalindrome(s, i, i);
		if (maxLength < len) {
			maxCenter = i;
			maxLength = len;
		}

		len = checkPalindrome(s, i - 1, i);
		if (maxLength < len) {
			maxCenter = i;
			maxLength = len;
		}

		i++;
	}

	// Calculate the begin index, alloc memory for result and set result.
	int begin = maxCenter - maxLength / 2;
	char *result = (char *) calloc(maxLength + 1, sizeof(char));
	for (i = 0; i < maxLength; i++) {
		result[i] = s[begin + i];
	}

	return result;
}
