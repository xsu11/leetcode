/*
 * ValidAnagram2.c
 *
 *  Created on: Sep 24, 2016
 *      Author: xinsu
 *
 * This solution allows the input to be unicode characters. But it is not collision-free.
 * Reference:
 * https://discuss.leetcode.com/topic/50077/euler-mersenne-fun-challenge
 * http://mathworld.wolfram.com/EulerPrime.html
 * https://en.wikipedia.org/wiki/Mersenne_prime
 */

/*
 Given two strings s and t, write a function to determine if t is an anagram of s.

 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.

 Note:
 You may assume the string contains only lowercase alphabets.

 Follow up:
 What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

long key(char *s) {
	long result = 1;
	int i = 0;
	while (s[i] != '\0') {
		int n = s[i++] - 'a';
		result = result * (n * n + n + 41) % INT_MAX;
	}

	return result;
}

bool isAnagram(char* s, char* t) {
	return key(s) == key(t);
}
