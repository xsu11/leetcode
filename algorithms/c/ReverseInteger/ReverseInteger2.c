/*
 * ReverseInteger2.c
 *
 *  Created on: Aug 30, 2016
 *      Author: xinsu
 */

/*
 Reverse digits of an integer.

 Example1: x = 123, return 321
 Example2: x = -123, return -321

 Have you thought about this?
 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

 Did you notice that the reversed integer might overflow?
 Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 Update (2014-11-10):
 Test cases had been added to test the overflow behavior.
 */

#include <stdio.h>
#include <limits.h>

int reverse(int x) {
	int result = 0;
	int remain = 0;

	while (x != 0) {
		remain = x % 10;

		/*
		 * Commented for the following reason:
		 * For INT_MAX, this goes overflowed if the high position - low position >= 2.
		 * Suppose INT_MAX = 5bbb3, let x = 4bbb5, the reversed result would be 5bbb4 which is overflowed.
		 * The same to INT_MIN
		 */
//		if (result > INT_MAX / 10 || result < INT_MIN / 10) {
//			return 0;
//		}
		if ((remain > 0 && result > (INT_MAX - remain) / 10)
				|| (remain < 0 && result < (INT_MIN - remain) / 10)) {
			return 0;
		}

		result = result * 10 + remain;
		x /= 10;
	}

	return result;
}
