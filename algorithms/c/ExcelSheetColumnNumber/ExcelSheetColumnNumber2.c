/*
 * ExcelSheetColumnNumber2.c
 *
 *  Created on: Sep 14, 2016
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
 Related to question Excel Sheet Column Title

 Given a column title as appear in an Excel sheet, return its corresponding column number.

 For example:

 A -> 1
 B -> 2
 C -> 3
 ...
 Z -> 26
 AA -> 27
 AB -> 28
 Credits:
 Special thanks to @ts for adding this problem and creating all test cases.
 */

#include <stdio.h>

int titleToNumber(char *s) {
	if (s == NULL || s[0] == '\0') {
		return 0;
	}

	int result = 0;

	int i = 0;
	while (s[i] != NULL) {
		result = 26 * result + (int) (s[i++] - 'A') + 1;
	}

	return result;
}
