/*
 * LongestSubstringWithoutRepeatingCharacters2.c
 *
 *  Created on: Sep 29, 2016
 *      Author: xinsu
 *
 * Suppose the input only contains ASCII code (int 0 ~ 127).
 */

/*
 Given a string, find the length of the longest substring without repeating characters.

 Examples:

 Given "abcabcbb", the answer is "abc", which the length is 3.

 Given "bbbbb", the answer is "b", with the length of 1.

 Given "pwwkew", the answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include <stdio.h>

int lengthOfLongestSubstring(char *s) {
	int maxLength = 0;
	int length = 0; // length of the legal substring
	int a[128] = { 0 }; // next index of last appeared s[end] in s
	int start = 0; // the start of a legal substring
	int end = 0; // the end of a legal substring
	while (s[end] != '\0') {
		if (a[s[end]] > start) {
			// meet a char that exists in the scaned range

			// calculate length
			length = end - start;
			if (maxLength < length) {
				maxLength = length;
			}

			// move start forward to the next index of the existed char
			start = a[s[end]];
		}
		a[s[end]] = ++end;
	}

	// when code comes here, we havn't checked the last substring
	length = end - start;
	if (maxLength < length) {
		maxLength = length;
	}

	return maxLength;
}
