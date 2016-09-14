/*
 * ExcelSheetColumnTitle.c
 *
 *  Created on: Sep 13, 2016
 *      Author: xinsu
 *
 * 1	A		1 (26 x 0 + A)
 * 2	B		2 (26 x 0 + B)
 * 3	...
 * 4	Z		26 (26 x 0 + Z)
 * 5	AA		26 x 1 + 1 (26 x A + A)
 * 6	AB		26 x 1 + 2 (26 x A + B)
 * 7	...		...
 * 8	AZ		26 x 1 + 26 (26 x A + Z) (deducted from line 5, 6)
 * 9	BA		26 x 2 + 1 (26 x B + A)
 * 10	BB		26 x 2 + 2 (26 x B + B)
 * 11	...		...
 * 12	BZ		26 x 2 + 26 (26 x B + Z) (deducted from line 9, 10)
 * 13 	...		...
 * 14	ZZ		26 x 26 + 26 (26 x Z + Z) (deducted from line 8, 12)
 * 15	AAA		26 x (26 x 1 + 1) + 1 (26 x AA + A)
 * 16	AAB		26 x (26 x 1 + 1) + 2 (26 x AA + B)
 * 17	...		...
 * 18	AAZ		26 x (26 x 1 + 1) + 26 (26 x AA + Z) (deducted from line 15, 16)
 * 19	ABA		26 x (26 x 1 + 2) + 1 (26 x AB + A)
 * 20	ABB		26 x (26 x 1 + 2) + 2 (26 x AB + B)
 * 21	...		...
 * 22	ABZ		26 x (26 x 1 + 2) + 26 (26 x AB + Z) (deducted from line 19, 20)
 * 23	...		...
 * 24	AZZ		26 x (26 x 1 + 26) + 26 (26 x AZ + A) (deducted from line 18, 22)
 * 25	BAA		26 x (26 x 2 + 1) + 1 (26 x BA + A)
 * 26	BAB		26 x (26 x 2 + 1) + 2 (26 x BA + B)
 * 27	...		...
 * 28	BAZ		26 x (26 x 2 + 1) + 26 (26 x BA + Z) (deducted from line 25, 26)
 * 29	BBA		26 x (26 x 2 + 2) + 1 (26 x BB + A)
 * 30	BBB		26 x (26 x 2 + 2) + 2 (26 x BB + B)
 * 31	...		...
 * 32	BBZ		26 x (26 x 2 + 2) + 26 (26 x BB + Z) (deducted from line 29, 30)
 * 33	...		...
 * 34	BZZ		26 x (26 x 2 + 26) + 26 (26 x BZ + Z) (deducted from line 28, 32)
 * 35	...		...
 * 36	ZZZ		26 x (26 x 26 + 26) + 26 (26 x ZZ + Z) (deducted from line 24, 34)
 * 37	AAAA	26 x (26 x (26 + 1) + 1) + 1 (26 x AAA + A)
 * 28	...		...
 */

/*
 Given a positive integer, return its corresponding column title as appear in an Excel sheet.

 For example:

 1 -> A
 2 -> B
 3 -> C
 ...
 26 -> Z
 27 -> AA
 28 -> AB
 Credits:
 Special thanks to @ifanchu for adding this problem and creating all test cases.

 Subscribe to see which companies asked this question
 */

#include <stdio.h>
#include <stdlib.h>

char *convertToTitle(int n) {
	if (n <= 0) {
		return NULL;
	}

	int length = 0;
	int num = n;
	while (num > 0) {
		length++;
		num = (num - 1) / 26;
	}

	char *result = (char *) calloc(length + 1, sizeof(char));
	int i = length - 1;
	int remainder = 0;
	num = n;
	while (num > 0) {
		// Because 0 <= remainder <= 25, when calculating the remainder, use num - 1 instead of num.
		remainder = (num - 1) % 26;
		result[i--] = (char) (remainder + 'A'); // 0 <= remainder <= 25
		num = (num - 1) / 26;
	}

	return result;
}
