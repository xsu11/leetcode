/*
 * ValidPalindrome.c
 *
 *  Created on: Sep 12, 2016
 *      Author: xinsu
 */

/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.

 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.

 For the purpose of this problem, we define empty string as valid palindrome.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		// isalnum(int c) checks if the input char is alphanumeric.
		// If it is, this function returns a non-zero digit.
		// this function is included in ctype.h
		int iIsAlnum = isalnum((int) s[i]);
		int jIsAlnum = isalnum((int) s[j]);

		if (iIsAlnum == 0 || jIsAlnum == 0) {
			if (iIsAlnum == 0) {
				i++;
			}
			if (jIsAlnum == 0) {
				j--;
			}
		} else if (tolower((int) s[i++]) != tolower((int) s[j--])) {
			return false;
		}
	}

	return true;
}
