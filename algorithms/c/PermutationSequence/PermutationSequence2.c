/*
 * PermutationSequence2.c
 *
 *  Created on: Nov 02, 2016
 *      Author: xinsu
 *
 * Iteration
 */

/*
 The set [1,2,3,…,n] contains a total of n! unique permutations.

 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):

 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.

 Note: Given n will be between 1 and 9 inclusive.
 */

#include <stdio.h>
#include <stdlib.h>

char *getPermutation(int n, int k) {
	if (n < 1 || k < 1) {
		return NULL;
	}

	// get step = (n - 1)!
	int step = 1;
	int i = 2;
	for (i = 2; i < n; i++) {
		step *= i;
	}

	if (k-- > step * n) {
		return NULL;
	}

	// alloc memory for the int array of k-th permutation and set initial value
	// remember to copy the result to the char array
	int *permut = (int *) calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		permut[i] = i + 1;
	}

	i = 0;
	while (k != 0) {
		int idx = i + k / step;
		int t = permut[idx];
		for (int j = idx - 1; j > i - 1; j--) {
			permut[j + 1] = permut[j];
		}
		permut[i] = t;

		k = k % step;
		step /= n - 1 - i;
		i++;
	}

	char *result = (char *) calloc(n, sizeof(char));
	for (i = 0; i < n; i++) {
		result[i] = permut[i] + '0';
	}

	free(permut);

	return result;
}
