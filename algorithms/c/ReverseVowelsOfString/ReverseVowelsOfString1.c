/*
 * ReverseVowelsOfString1.c
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

char *reverseVowels(char *s) {
	int length = strlen(s);

	if (length <= 1) {
		return s;
	}

	int i = 0;
	int j = length - 1;
	while (i < j) {
		while (i < j && !isvowel(s[i])) {
			i++;
		}

		while (i < j && !isvowel(s[j])) {
			j--;
		}

		// swap
		char t = s[i];
		s[i] = s[j];
		s[j] = t;

		i++;
		j--;
	}

	return s;
}
