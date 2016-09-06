/*
 * LengthOfLastWord.c
 *
 *  Created on: Sep 05, 2016
 *      Author: xinsu
 *
 * This solution only considers the input string consists only A~Z and a~z and white space.
 * It is easy to change the code to meet situation when string contains more than letters.
 *
 */

/*
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 return the length of last word in the string.

 If the last word does not exist, return 0.

 Note: A word is defined as a character sequence consists of non-space characters only.

 For example,
 Given s = "Hello World",
 return 5.
 */

#include <stdio.h>

int lengthOfLastWord(char* s) {
	int result = 0;

	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != '\0') {
			result = 0;
		} else if (s[i] != ' ') {
			result++;
		}
		i++;
	}

	return result;
}
