/*
 * ReverseVowelsOfString2.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 *
 * Reverse string in place.
 */

/*
 Write a function that takes a string as input and reverse only the vowels of a string.

 Example 1:
 Given s = "hello", return "holle".

 Example 2:
 Given s = "leetcode", return "leotcede".

 Note:
 The vowels does not include the letter "y".
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isvowel(char s) {
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' || s == 'A'
			|| s == 'E' || s == 'I' || s == 'O' || s == 'U') {
		return true;
	}

	return false;
}

char *reverseString(char *s) {
	int length = strlen(s);

	if (length <= 1) {
		return s;
	}

	char t = NULL;
	for (int i = 0; i < length / 2; i++) {
		if (s[i] != s[length - 1 - i]) {
			t = s[i];
			s[i] = s[length - 1 - i];
			s[length - 1 - i] = t;
		}
	}

	return s;
}

char *reverseVowels(char *s) {
	int length = strlen(s);

	if (length <= 1) {
		return s;
	}

	char *vs = (char *) calloc(length + 1, sizeof(char));
	int *vIdx = (int *) calloc(length, sizeof(int));
	int vLength = 0;

	int i = 0;
	int j = 0;
	for (i = 0; i < length; i++) {
		if (isvowel(s[i])) {
			vLength++;
			vs[j] = s[i];
			vIdx[j++] = i;
		}
	}

	vs = reverseString(vs);

	for (i = 0; i < vLength; i++) {
		s[vIdx[i]] = vs[i];
	}

	free(vs);
	free(vIdx);
	return s;
}
