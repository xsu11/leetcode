/*
 * IsomorphicStrings1.c
 *
 *  Created on: Sep 19, 2016
 *      Author: xinsu
 *
 * Use twy arrays to store an s-t pair.
 */

/*
 Given two strings s and t, determine if they are isomorphic.

 Two strings are isomorphic if the characters in s can be replaced to get t.

 All occurrences of a character must be replaced with another character while preserving the order of characters.
 No two characters may map to the same character but a character may map to itself.

 For example,
 Given "egg", "add", return true.

 Given "foo", "bar", return false.

 Given "paper", "title", return true.

 Note:
 You may assume both s and t have the same length.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char* s, char* t) {
	int sLength = strlen(s);
	int tLength = strlen(t);

	if (s == NULL || t == NULL || sLength != tLength) {
		return false;
	}

	char *sMap = (char *) calloc(sLength, sizeof(char));
	char *tMap = (char *) calloc(tLength, sizeof(char));

	int sti = 0;
	int i = 0;
	for (i = 0; i < sLength; i++) {
		int j = 0;
		while (j < sti && (sMap[j] != s[i] || tMap[j] != t[i])) {
			if (sMap[j] != s[i] && tMap[j] != t[i]) {
				j++;
			} else {
				return false;
			}
		}

		if (j == sti) {
			sMap[j] = s[i];
			tMap[j] = t[i];
			sti++;
		}
	}

	free(sMap);
	free(tMap);

	return true;
}
