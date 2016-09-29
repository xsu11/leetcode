/*
 * RansomeNote.c
 *
 *  Created on: Sep 29, 2016
 *      Author: xinsu
 *
 * Assume the inputs are all lowercase letters
 */

/*
 Given an arbitrary ransom note string and another string containing letters from all the magazines,
 write a function that will return true if the ransom note can be constructed from the magazines;
 otherwise, it will return false.

 Each letter in the magazine string can only be used once in your ransom note.

 Note:
 You may assume that both strings contain only lowercase letters.

 canConstruct("a", "b") -> false
 canConstruct("aa", "ab") -> false
 canConstruct("aa", "aab") -> true
 */

#include <stdio.h>
#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
	int a[26] = { 0 };

	int i = 0;
	while (magazine[i] != '\0') {
		a[magazine[i++] - 'a']++;
	}

	i = 0;
	while (ransomNote[i] != '\0') {
		if (a[ransomNote[i] - 'a'] == 0) {
			return false;
		}

		a[ransomNote[i++] - 'a']--;
	}

	return true;
}

