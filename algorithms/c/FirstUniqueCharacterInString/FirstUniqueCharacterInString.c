/*
 * FirstUniqueCharacterInString.c
 *
 *  Created on: Sep 29, 2016
 *      Author: xinsu
 *
 * Assume the inputs are all lowercase letters
 */

/*
 Given a string, find the first non-repeating character in it and return it's index.
 If it doesn't exist, return -1.

 Examples:

 s = "leetcode"
 return 0.

 s = "loveleetcode",
 return 2.
 Note: You may assume the string contain only lowercase letters.
 */

#include <stdio.h>

int firstUniqChar(char *s) {
	int a[26] = { 0 };

	int i = 0;
	while (s[i] != '\0') {
		a[s[i++] - 'a']++;
	}

	i = 0;
	while (s[i] != '\0') {
		if (a[s[i] - 'a'] == 1) {
			return i;
		}

		i++;
	}

	return -1;
}

