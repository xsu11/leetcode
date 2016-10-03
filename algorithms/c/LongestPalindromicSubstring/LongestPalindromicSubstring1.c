/*
 * LongestPalindromicSubstring1.c
 *
 *  Created on: Sep 30, 2016
 *      Author: xinsu
 *
 * Dynamic programming, trying to use only upper right triangle of the table.
 * O(n^2) time and O(n^2) space.
 * If we do not use calloc, it will save a little time when calling this function repeatedly.
 */

/*
 Given a string S, find the longest palindromic substring in S.
 You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *longestPalindrome(char *s) {
	int length = strlen(s);

	if (length < 1) {
		return NULL;
	}

	// alloc memory
	bool **p = (bool **) calloc(length, sizeof(bool *));
	int i = 0;
	for (i = 0; i < length; i++) {
		p[i] = (bool *) calloc(length - i, sizeof(bool));
	}

	int begin = 0;
	int maxLength = 1;

	// base case:
	// p[i][i] = true, that is p[i][0] = true
	// p[i][i + 1] = (s[i] == s[i+1]), that is p[i][1] = (s[i] == s[i+1])
	for (i = 0; i < length - 1; i++) {
		p[i][0] = true;
		if (s[i] == s[i + 1]) {
			p[i][1] = true;
			begin = i;
			maxLength = 2;
		}
	}
	p[i][0] = true;

	// fill out the rest of the table
	// p[i][j] = (p[i + 1][j - 1] && s[i] == s[j]), that is p[i][j] = (p[i + 1][j - 2] && s[i] == s[j + i])
	for (int j = 2; j < length; j++) {
		for (i = 0; i < length - j; i++) {
			if (p[i + 1][j - 2] == true && s[i] == s[j + i]) {
				p[i][j] = true;
				begin = i;
				maxLength = j + 1;
			}
		}
	}

	char *result = (char *) calloc(maxLength + 1, sizeof(char));
	for (i = 0; i < maxLength; i++) {
		result[i] = s[begin + i];
	}

	// free memory
	for (i = 0; i < length; i++) {
		free(p[i]);
	}
	free(p);

	return result;
}
