/*
 * LetterCombinationsOfPhoneNumber.c
 *
 *  Created on: Oct 05, 2016
 *      Author: xinsu
 */

/*
 Given a digit string, return all possible letter combinations that the number could represent.

 A mapping of digit to letters (just like on the telephone buttons) is given below.

 1(   ) , 2(abc), 3(def)
 4(ghi) , 5(jkl), 6(mno)
 7(pqrs), 8(tuv), 9(wxyz)
 *(+)   , 0(_)  , #(^)

 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char **letterCombinations(char *digits, int *returnSize) {
	if (digits == NULL || digits[0] == '\0') {
		*returnSize = 0;
		return NULL;
	}

	// get total length of the results array and the length of the input string
	int totalLength = 1;
	int i = 0;
	while (digits[i] != '\0') {
		if (digits[i] < '2' || digits[i] > '9') {
			*returnSize = 0;
			return NULL;
		} else if (digits[i] == '7' || digits[i] == '9') {
			totalLength *= 4;
		} else {
			totalLength *= 3;
		}

		i++;
	}
	int length = i;

	// alloc memory for results array
	*returnSize = totalLength;
	char **results = (char **) calloc(totalLength, sizeof(char *));
	for (i = 0; i < totalLength; i++) {
		results[i] = (char *) calloc(length, sizeof(char));
	}

	int prevSegLen = totalLength;
	for (i = 0; i < length; i++) { // i is the column number
		// calculate how many segments does this column has and
		// get the same begining char for each segment
		int charLen = 0;
		char beginChar = NULL;
		if (digits[i] == '7' || digits[i] == '9') {
			charLen = 4;
			beginChar = (digits[i] == '7') ? 'p' : 'w';
		} else {
			charLen = 3;
			beginChar = (digits[i] == '8') ? 't' : 'a' + 3 * (digits[i] - '2');
		}

		// calculate this column's segment length
		int curSegLen = prevSegLen / charLen;

		for (int j = 0, curSegNum = 0; j < totalLength;
				j += curSegLen, curSegNum++) { // j is the begin row index of curSegLen
			// for loop to set all values to the same char
			for (int k = j; k < j + curSegLen; k++) { // k is the row index inside a segment
				results[k][i] = beginChar + curSegNum % charLen;
			}
		}

		// after setting this column, the segment length becomes previous segment length
		prevSegLen = curSegLen;
	}

	return results;
}
