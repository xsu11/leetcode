/*
 * CountPrimes1.c
 *
 *  Created on: Sep 19, 2016
 *      Author: xinsu
 */

/*
 Description:

 Count the number of prime numbers less than a non-negative number, n.

 Credits:
 Special thanks to @mithmatt for adding this problem and creating all test cases.

 Hint:

 Let's start with a isPrime function.
 To determine if a number is prime, we need to check if it is not divisible by any number less than n.
 The runtime complexity of isPrime function would be O(n) and
 hence counting the total prime numbers up to n would be O(n^2).
 Could we do better?
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(int n) {
	if (n < 4) {
		return n > 1;
	}

	int i = 2;
	for (i = 2; i < sqrt(n) + 1; i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int countPrimes(int n) {
	int result = 0;

	int i = 2;
	for (i = 2; i < n; i++) {
		if (isPrime(i) == true) {
			result++;
		}
	}

	return result;
}
