/*
 * ImplementStrStr1.c
 *
 *  Created on: Sep 03, 2016
 *      Author: xinsu
 *
 * This FSM algorithm has a problem: it won't check back.
 */

/*
 Implement strStr().

 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <stdio.h>

#define START 0
#define OUT 1
#define IN 2
#define END 3

int strStr(char* haystack, char* needle) {
	if (needle[0] == '\0') {
		return 0;
	} else if (haystack[0] == '\0') {
		return -1;
	}

	int result = -1;
	int state = START;

	int h = 0;
	int n = 0;
	while (state != END) {
		if (state == START) {
			if (haystack[h] != needle[n]) {
				// start finding, not start match
				state = OUT;
			} else {
				// start match
				result = h;
				n++;
				state = IN;
			}
		} else if (state == OUT) {
			if (haystack[h] != '\0' && needle[n] != '\0') {
				if (haystack[h] == needle[n]) {
					// start match
					result = h;
					state = IN;
				}
				n++;
			} else {
				state = END;
			}
		} else if (state == IN) {
			if (haystack[h] != '\0' && needle[n] != '\0') {
				if (haystack[h] != needle[n]) {
					// stop match
					result = -1;
					state = OUT;
				}
				n++;
			} else if (needle[n] == '\0') {
				// find match;
				state = END;
			} else {
				// haystack goes to the end, not find
				result = -1;
				state = END;
			}
		}
		h++;
	}

	return result;
}
