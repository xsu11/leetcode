/*
 * StrTokenizeToBuffer.c
 *
 Write a function
 StrTokenizeToBuffer() that
 incrementally tokenizes a
 string, similar to the C runtime
 library function strtok(), but
 that copies output tokens to a
 separate string buffer instead
 of null terminating them in-
 place in the source string.
 Be sure to handle all
 exceptional cases.
 Be as efficient as possible.
 Do not use standard library
 functions or containers in your
 response.
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define OUT 0
#define STRING 1
#define DELIMITER 2
#define END 3

bool StrTokenizeToBuffer(char * buffer, int bufferChars, const char ** string,
		const char delimiters[]) {
	if (string[0][0] == '\0') {
		return false;
	}

	int i = 0;

	// clean buffer
	for (i = 0; i < bufferChars; i++) {
		buffer[i] = '\0';
	}

	int idxStringStart = 0;
	int idxDelimiterStart = 0;
	int idxDelimiterStop = 0;

	int state = OUT;

	i = 0;
	while (state != END) {
		// check if cur[i] is a delimiter
		bool isDelimiter = false;
		int j = 0;
		while (isDelimiter == false && delimiters[j] != '\0') {
			if (string[0][i] == delimiters[j]) {
				isDelimiter = true;
			} else {
				j++;
			}
		}

		if (state == OUT) {
			if (string[0][i] == '\0') {
				// found token and set idxDelimiterStop
				idxDelimiterStop = i; // change state
				state = END; // change state
			} else if (!isDelimiter) {
				idxStringStart = i;
				state = STRING; // change state
			}
		} else if (state == STRING) {
			if (string[0][i] == '\0') {
				idxDelimiterStart = i;
				idxDelimiterStop = i;
				state = END; // change state
			} else if (isDelimiter) {
				// set delimiter start index
				idxDelimiterStart = i;
				state = DELIMITER; // change state
			}
		} else if (state == DELIMITER) {
			if (string[0][i] == '\0') {
				idxDelimiterStop = i;
				state = END; // change state
			} else if (!isDelimiter) {
				idxDelimiterStop = i;
				state = END; // change state
			}
		}

		i++;
	}

	// check if the length of the found token > bufferChars
	if (idxDelimiterStart + 1 - idxStringStart > bufferChars) {
		return false;
	}

	// copy 0 to idxDelimiterStart to buffer
	for (i = idxStringStart; i < idxDelimiterStart; i++) {
		buffer[i - idxStringStart] = (*string)[i];
	}

	// set string point to idxDelimiterStop
	string[0] += idxDelimiterStop;

	return true;
}

//void test(char **s) {
//	printf("s = %c\n", (*s)[0]);
//	s[0] += 2;
//}
//
//int main () {
//	char *s = "123456789";
//	test(&s);
//	test(&s);
//	test(&s);
//}

//int main() {
////	FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
//	bool res;
//
//	unsigned _bufferChars = 256;
////	scanf("bufferChars = %u", &_bufferChars);
//
//	char * _buffer = (char *) malloc(_bufferChars * sizeof(char));
//
////	char * _string = (char *) malloc(10240 * sizeof(char));
////	scanf("string = \n%[^\n]", _string);
//
//	char * _string = " this is an exmple.";
//
////	char * _delimiters = (char *) malloc(1024 * sizeof(char));
////	scanf("delimiters = \n%[^\n]", _delimiters);
//	char * _delimiters = " ";
//
//	// space always a delimiter, just because
////	_delimiters[strlen(_delimiters) + 1] = '\0';
////	_delimiters[strlen(_delimiters)] = ' ';
//
//	for (const char * curr = _string;
//			StrTokenizeToBuffer(_buffer, _bufferChars, &curr, _delimiters);)
//		printf("%s\n", _buffer);
//
////	fclose(f);
//	return 0;
//}
