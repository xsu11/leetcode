/*
 * LongestCommonPrefix.c
 *
 *  Created on: Aug 31, 2016
 *      Author: xinsu
 */

/*
 Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <stdio.h>

char *longestCommonPrefix(char **strs, int strsSize) {
	char * result;

	if (strs[0] == '\0') {
		result = (char *) calloc(1, sizeof(char));
		return result;
	}

	int col = 0;
	int row = 0;
	for (col = 0; col < strlen(strs[0]); col++) {
		for (row = 1; row < strsSize; row++) {
			if (strs[row][col] == '\0') {
				result = (char *) calloc(col + 1, sizeof(char));
				strcpy(result, strs[row]);
				return result;
			} else if (strs[row][col] != strs[0][col]) {
				result = (char *) calloc(col + 1, sizeof(char));
				strncpy(result, strs[row], col);
				return result;
			}
		}
	}

	result = (char *) calloc(col + 1, sizeof(char));
	strcpy(result, strs[0]);
	return result;
}
