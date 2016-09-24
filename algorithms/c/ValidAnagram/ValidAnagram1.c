/*
 * ValidAnagram1.c
 *
 *  Created on: Sep 23, 2016
 *      Author: xinsu
 *
 * This solution only allows the input to be a~z.
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

bool isAnagram(char* s, char* t) {
	int a[26] = { 0 };
	int i = 0;
	while (s[i] != '\0' && t[i] != '\0') {
		a[s[i] - 'a']++;
		a[t[i] - 'a']--;
		i++;
	}

	if (s[i] != '\0' || t[i] != '\0') {
		return false;
	}

	for (i = 0; i < 25; i++) {
		if (a[i] != 0) {
			return false;
		}
	}

	return true;
}
