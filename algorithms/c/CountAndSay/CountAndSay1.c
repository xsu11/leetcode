/*
 * CountAndSay1.c
 *
 *  Created on: Sep 05, 2016
 *      Author: xinsu
 *
 * Recursion
 *
 */

/*
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.

 Note: The sequence of integers will be represented as a string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *countNext(char *s, int ith, int n) {
	// base case
	if (ith > n) {
		return s;
	}

	// get new string
	char *newS = (char *) calloc(strlen(s) * 2 + 1, sizeof(char));
	char prevChar = s[0];
	int count = 0;
	int i = 0;
	int j = 0;
	while (s[i] != '\0') {
		if (s[i] != prevChar) {
			// save to newS
			newS[j++] = count + '0';
			newS[j++] = prevChar;
			prevChar = s[i];
			count = 1;
		} else {
			count++;
		}
		i++;
	}

	// set final string and the end '\0'
	newS[j++] = count + '0';
	newS[j++] = prevChar;
	newS[j] = '\0';

	free(s);

	// this tail recursion can be transformed into a iteration
	return countNext(newS, ith + 1, n);
}

char *countAndSay(int n) {
	char *s = (char *) calloc(2, sizeof(char));
	s[0] = '1';

	if (n <= 1) {
		return s;
	}

	return countNext(s, 2, n);
}
