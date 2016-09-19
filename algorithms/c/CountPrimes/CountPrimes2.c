/*
 * CountPrimes2.c
 *
 *  Created on: Sep 19, 2016
 *      Author: xinsu
 *
 * A basic format of Sieve of Eratosthenes
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
#include <stdlib.h>

int countPrimes(int n) {
	if (n < 2) {
		return 0;
	}

	int result = 0;
	char *primes = (char *) calloc(n, sizeof(char));

	int i = 2;
	for (i = 2; i < n; i++) {
		if (primes[i] == '\0') {
			result++;

			int j = i;
			while ((j += i) < n) {
				primes[j] = '1';
			}
		}
	}

	free(primes);
	return result;
}
