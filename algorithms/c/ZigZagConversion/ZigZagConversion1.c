/*
 * ZigZagConversion1.c
 *
 *  Created on: Aug 26, 2016
 *      Author: xinsu
 *
 * This solution wont't survive from case ("glzamzp", 5) on LeetCode,
 * even it shows the same result when running it in Custome case.
 * The LeetCode.com OJ may have some bug. Still need to figure out.
 */

/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

#include <stdio.h>
#include <string.h>

char *convert(char *s, int numRows) {
	size_t length = strlen(s);

	// no need to do conversion
	if (numRows <= 1 || numRows >= length) {
		return s;
	}

	// allocate memory
	char *result = (char *) calloc(length, sizeof(char));
	char **r = (char **) calloc(numRows, sizeof(char *));

	int i = 0;
	for (i = 0; i < numRows; i++) {
		*(r + i) = (char *) calloc(length, sizeof(char));
	}

	// step =  1: down
	// step = -1: up
	int step = 1;

	int row = 0;

	// start to traverse s
	for (i = 0; i < length; i++) {
		// decide direction by setting step
		if (row == 0) {
			step = 1;
		} else if (row == numRows - 1) {
			step = -1;
		}

		// concatinate s[i] to r[i]
		strncat(r[row], s + i, 1);
		row += step;
	}

	// set result
	for (i = 0; i < numRows; i++) {
		strcat(result, r[i]);
	}

	// free memory
	for (i = 0; i < numRows; i++) {
		free(r[i]);
	}
	free(r);

	return result;
}
