/*
 * LongestPalindromicSubstring4.c
 *
 *  Created on: Sep 30, 2016
 *      Author: xinsu
 *
 * Manacher's ALGORITHM: O(n) time and O(n) space
 * Reference: http://articles.leetcode.com/longest-palindromic-substring-part-ii/
 */

/*
 Given a string S, find the longest palindromic substring in S.
 You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processString(char *s, int sLength, char *t, int tLength) {
	if (tLength != (sLength + 1) * 2) {
		return;
	}

	t[0] = '^';
	t[1] = '#';

	int i = 0;
	int j = 2;
	for (; i < sLength; i++, j = j + 2) {
		t[j] = s[i];
		t[j + 1] = '#';
	}
}

char *longestPalindrome(char *s) {
	int sLength = strlen(s);

	if (sLength < 1) {
		return NULL;
	}

	int tLength = (sLength + 1) * 2;
	char *t = (char *) calloc(tLength + 1, sizeof(char));
	int *p = (int *) calloc(tLength, sizeof(int));

	// pre process input string
	processString(s, sLength, t, tLength);

	int center = 1;
	int right = 1;
	int maxLength = 0;
	int maxCenter = 1;

	int i = 2;
	for (i = 2; i < tLength - 1; i++) {
		int j = center * 2 - i; // j is the mirror index of i, j = center + (center - i)
		int range = right - i; // this is the range between i and right boundry

		// set p[i]
		if (range <= 0) {
			p[i] = 0;
		} else if (p[j] > range) {
			p[i] = range;
		} else {
			// the condition is: range > 0 && p[j] <= range
			p[i] = p[j];
		}

		// if range <= 0, then i <= right, it will go into this while
		// else if p[j] > range, then p[i] needs to expand further to get p[i], it will go into this while
		// else, it won't go into this while
		//
		// each case when it goes into the while, it will check the expansion starting from the max(right, i)
		// and later we will set the right boundry to this new one (i + p[i])
		// therefore this while loop will only run at most sLength times during the entire for loop.
		while (t[i - p[i] - 1] == t[i + p[i] + 1]) {
			p[i]++;
		}

		// check if the length is larger
		if (maxLength < p[i]) {
			maxLength = p[i];
			maxCenter = i;
		}

		// set new right boundry and new center if necessary
		// iff range > 0 && p[j] > range, it may set the new boundry (if p[i] + i = range then it won't set)
		int boundryLength = i + p[i];
		if (boundryLength > right) {
			center = i;
			right = boundryLength;
		}
	}

	// calculate the begin index and alloc memory for result and set result
	int begin = (maxCenter - 1 - maxLength) / 2;
	char *result = (char *) calloc(maxLength + 1, sizeof(char));
	for (i = 0; i < maxLength; i++) {
		result[i] = s[i + begin];
	}

	// free memory
	free(t);
	free(p);

	return result;
}
