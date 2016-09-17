/*
 * HappyNumber1.c
 *
 *  Created on: Sep 17, 2016
 *      Author: xinsu
 *
 * Reference: https://en.wikipedia.org/wiki/Happy_number
 * The loop is: 4, 16, 37, 58, 89, 145, 42, 20, 4, ...
 * Of course we can use a hash set to store them and check if the transformed number comes to any one above.
 * This solution gets the idea in problem Linked List Cycle, using two pointers to race.
 */

/*
 Write an algorithm to determine if a number is "happy".

 A happy number is a number defined by the following process:
 Starting with any positive integer, replace the number by the sum of the squares of its digits,
 and repeat the process until the number equals 1 (where it will stay),
 or it loops endlessly in a cycle which does not include 1.
 Those numbers for which this process ends in 1 are happy numbers.

 Example: 19 is a happy number

 1^2 + 9^2 = 82
 8^2 + 2^2 = 68
 6^2 + 8^2 = 100
 1^2 + 0^2 + 0^2 = 1

 Credits:
 Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>

int nextNum(int n) {
	if (n <= 0) {
		return 0;
	}

	int result = 0;

	while (n != 0) {
		int remainder = n % 10;
		result += remainder * remainder;
		n /= 10;
	}

	return result;
}

bool isHappy(int n) {
	if (n <= 0) {
		return false;
	}

	int turtle = n;
	int rabbit = nextNum(nextNum(n));

	while (turtle != rabbit) {
		turtle = nextNum(turtle);
		rabbit = nextNum(nextNum(rabbit));
	}

	return (rabbit == 1) ? true : false;
}
