/*
 * IsomorphicStrings2.c
 *
 *  Created on: Sep 19, 2016
 *      Author: xinsu
 *
 * ASCII table: Use two arrays of 256 length.
 * The index of sMap[i] is the ASCII code of s[i], the value of stMap[i] is t[i].
 * The index of ttMap[i] is the ASCII code of t[i], the value of ttMap[i] is s[i].
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

	char *sMap = (char *) calloc(256, sizeof(char));
	char *tMap = (char *) calloc(256, sizeof(char));

	int i = 0;
	for (i = 0; i < sLength; i++) {
		int sidx = (int) s[i];
		int tidx = (int) t[i];
		if (sMap[sidx] == '\0' && tMap[tidx] == '\0') {
			sMap[sidx] = t[i];
			tMap[tidx] = s[i];
		} else if (sMap[sidx] != t[i] || tMap[tidx] != s[i]) {
			return false;
		}
	}

	free(sMap);
	free(tMap);
	return true;
}
