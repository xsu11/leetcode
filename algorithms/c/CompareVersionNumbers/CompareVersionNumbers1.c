/*
 * CompareVersionNumbers1.c
 *
 *  Created on: Sep 13, 2016
 *      Author: xinsu
 *
 * This solution uses string's functions strtok() and atoi() in stdlib.h.
 * Warning: this solution has no check on illegal input.
 * If the input is beyond numbers and dot, it will definitely fail.
 * The atoi() doesn't have any check on its input,
 * therefore unless you make sure the input is correct, try not to use it as best as you can.
 */

/*
 Compare two version numbers version1 and version2.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

 You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three",
 it is the fifth second-level revision of the second first-level revision.

 Here is an example of version numbers ordering:

 0.1 < 1.1 < 1.2 < 13.37
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareVersion(char* version1, char* version2) {
	char *token1 = version1;
	char *token2 = version2;
	int ver1 = 0;
	int ver2 = 0;

	while (token1 != NULL || token2 != NULL) {
		ver1 = 0;
		ver2 = 0;

		if (token1 != NULL) {
			ver1 = atoi(strtok(token1, "."));
			token1 = strtok(NULL, "\0"); // set token to the rest of the string
		}

		if (token2 != NULL) {
			ver2 = atoi(strtok(token2, "."));
			token2 = strtok(NULL, "\0"); // set token to the rest of the string
		}

		if (ver1 > ver2) {
			return 1;
		} else if (ver1 < ver2) {
			return -1;
		}
	}

	return 0;
}
