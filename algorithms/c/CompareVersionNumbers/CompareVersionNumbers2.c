/*
 * CompareVersionNumbers2.c
 *
 *  Created on: Sep 13, 2016
 *      Author: xinsu
 *
 * Parse the string manually.
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
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compareVersion(char *version1, char *version2) {
	int length1 = strlen(version1);
	int length2 = strlen(version2);

	if (length1 == 0 || length2 == 0) {
		return 0;
	}

	int ver1 = 0;
	int ver2 = 0;

	int i1 = 0;
	int i2 = 0;
	while (i1 < length1 || i2 < length2) {
		ver1 = 0;
		ver2 = 0;

		// Warn: when the following parsings happen, here is no check for illegal input!

		// parse version1
		while (i1 < length1 && isdigit(version1[i1])) {
			ver1 = ver1 * 10 + version1[i1++] - '0';
		}
		i1 = (version1[i1] == '.') ? (i1 + 1) : i1;

		// parse version2
		while (i2 < length2 && isdigit(version2[i2])) {
			ver2 = ver2 * 10 + version2[i2++] - '0';
		}
		i2 = (version2[i2] == '.') ? (i2 + 1) : i2;

		if (ver1 > ver2) {
			return 1;
		} else if (ver1 < ver2) {
			return -1;
		}
	}

	return 0;
}
