/*
 * PalindromeNumber.c
 *
 *  Created on: Aug 31, 2016
 *      Author: xinsu
 */

/*
 Determine whether an integer is a palindrome. Do this without extra space.

 click to show spoilers.

 Some hints:
 Could negative integers be palindromes? (ie, -1)

 If you are thinking of converting the integer to string, note the restriction of using extra space.

 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
 you know that the reversed integer might overflow. How would you handle such case?

 There is a more generic way of solving this problem.
 */

#include <stdio.h>
#include <stdbool.h>

// bool isPalindrome(int x) {
//     return (x>= 0 && x == reverse(x));
// }

bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}

	int length = 0;
	int a = x;
	while (a != 0) {
		length++;
		a /= 10;
	}

	int i = 0;
	int n[length];
	while (x != 0) {
		n[i++] = x % 10;
		x /= 10;
	}

	for (i = 0; i < length / 2; i++) {
		if (n[i] != n[length - 1 - i]) {
			return false;
		}
	}

	return true;
}
