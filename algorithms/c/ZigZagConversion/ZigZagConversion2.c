/*
 * ZigZagConversion2.c
 *
 *  Created on: Aug 27, 2016
 *      Author: xinsu
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

char* convert(char* s, int numRows) {
	size_t length = strlen(s);

	if (numRows <= 1 || numRows >= length) {
		return s;
	}

	char *result = (char *) malloc(length * sizeof(char));
	int step = 2 * (numRows - 1);

	int sets = length / step;
	int remain = length % step; // 0 <= remain <= step - 1

	int line = 0;
	int set = 0;
	int curPos = 0;

	// first row
	for (set = 0; set < sets || (set == sets && remain > 0); set++, curPos++) {
		result[curPos] = s[curPos * step];
	}

	// middle row
	for (line = 1; line < numRows - 1; line++) {
		for (set = 0; set < sets; set++, curPos++) {
			result[curPos++] = s[set * step + line];
			result[curPos] = s[(set + 1) * step - line];
		}

		if (remain > line - 1) {
			result[curPos] = s[sets * step + line];
			curPos++;
		}

		if (remain > numRows && remain - numRows >= numRows - 1 - line) {
			result[curPos] = s[(set + 1) * step - line];
			curPos++;
		}
	}

	// last row
	for (set = 0; set < sets || (set == sets && remain >= numRows);
			set++, curPos++) {
		result[curPos] = s[set * step + numRows - 1];
	}

	return result;
}
