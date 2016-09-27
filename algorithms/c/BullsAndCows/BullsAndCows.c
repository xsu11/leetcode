/*
 * BullsAndCows.c
 *
 *  Created on: Sep 27, 2016
 *      Author: xinsu
 */

/*
 You are playing the following Bulls and Cows game with your friend:
 You write down a number and ask your friend to guess what the number is.
 Each time your friend makes a guess, you provide a hint that
 indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and
 how many digits match the secret number but locate in the wrong position (called "cows").
 Your friend will use successive guesses and hints to eventually derive the secret number.

 For example:

 Secret number:  "1807"
 Friend's guess: "7810"
 Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 Write a function to return a hint according to the secret number and friend's guess,
 use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

 Please note that both secret number and friend's guess may contain duplicate digits, for example:

 Secret number:  "1123"
 Friend's guess: "0111"
 In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
 You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

 Credits:
 Special thanks to @jeantimex for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>

int intLength(int a) {
	int length = 0;
	if (a == 0) {
		length++;
	} else {
		while (a != 0) {
			length++;
			a /= 10;
		}
	}
	return length;
}

int myItos(int a, char *s, int i) {
	if (a == 0) {
		s[i--] = '0';
	} else {
		while (a != 0) {
			s[i--] = a % 10 + '0';
			a /= 10;
		}
	}

	return i;
}

char* getHint(char* secret, char* guess) {
	int bulls = 0;
	int cows = 0;

	int sec[10] = { 0 };
	int gue[10] = { 0 };

	int i = 0;
	while (secret[i] != '\0' && guess[i] != '\0') {
		if (secret[i] == guess[i]) {
			bulls++;
		} else {
			sec[secret[i] - '0']++;
			gue[guess[i] - '0']++;
		}
		i++;
	}

	for (int i = 0; i < 10; i++) {
		if (sec[i] > 0 && gue[i] > 0) {
			cows += sec[i] < gue[i] ? sec[i] : gue[i];
		}
	}

	int length = intLength(bulls) + intLength(cows) + 3;
	char *result = (char *) calloc(length, sizeof(char));

	i = length - 2;
	result[i--] = 'B';
	i = myItos(cows, result, i);
	result[i--] = 'A';
	i = myItos(bulls, result, i);

	return result;
}
