/*
 * AddDigits1.c
 *
 *  Created on: Sep 26, 2016
 *      Author: xinsu
 *
 * Naive solution
 */

/*
 Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

 For example:

 Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

 Follow up:
 Could you do it without any loop/recursion in O(1) runtime?

 Hint:

 A naive implementation of the above process is trivial. Could you come up with other methods?
 What are all the possible results?
 How do they occur, periodically or randomly?
 You may find this Wikipedia article useful.

 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <stdio.h>

int addDigits(int num) {
	int result = num;

	while (result >= 10) {
		num = result;
		result = 0;
		while (num != 0) {
			result += num % 10;
			num /= 10;
		}
	}

	return result;
}
