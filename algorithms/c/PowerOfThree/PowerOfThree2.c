/*
 * PowerOfThree2.c
 *
 *  Created on: Sep 28, 2016
 *      Author: xinsu
 *
 * There is a unresolved problem:
 * suppose n = 243 (3^5)
 * the following code will get wrong answer:
 *
 * int p = (int) (log((double) n) / log(3.0));
 * int x = (int) pow(3.0, (double) p);
 *
 * p's value is 4, not 5. If I change code to:
 *
 * double d = log((double) n) / log(3.0);
 * int p = (int) (d);
 * int x = (int) pow(3.0, (double) p);
 *
 * then d's value is 5.00000.
 *
 * Solution is: either add 0.5 to the d, or use n + 1 instead if n.
 */

/*
 Given an integer, write a function to determine if it is a power of three.

 Follow up:
 Could you do it without using any loop / recursion?

 Credits:
 Special thanks to @dietpepsi for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

bool isPowerOfThree(int n) {
	if (n < 1) {
		return false;
	}

	int x = (int) pow(3.0, (double) (int) (log((double) (n + 1)) / log(3.0)));
	return x == n;
}
