/*
 * PermutationSequence1.c
 *
 *  Created on: Nov 02, 2016
 *      Author: xinsu
 *
 * Recursion
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

void getKthPermutSeq(int *permut, int nf, int n, int k, int curPos) {
	// base case
	if (curPos == n) {
		return;
	}

	int nele = n - curPos; // the count of elements in permut those still need to arrange
	int step = nf / nele;

	int i = 1;
	while (i < nele && step * i < k) {
		i++;
	}
	k -= (i - 1) * step;

	// insert the (curPos + i)-th element in permut to the curPos-th position
	int t = permut[curPos + i - 1];
	for (i = curPos + i - 2; i > curPos - 1; i--) {
		permut[i + 1] = permut[i];
	}
	permut[curPos] = t;

	getKthPermutSeq(permut, step, n, k, curPos + 1);
}

char *getPermutation(int n, int k) {
	if (n < 1 || k < 1) {
		return NULL;
	}

	// get n's factorial
	int nf = 1;
	int i = 2;
	for (i = 2; i < n + 1; i++) {
		nf *= i;
	}

	if (k > nf) {
		return NULL;
	}

	// alloc memory for the int array of k-th permutation and set initial value
	// remember to copy the result to the char array
	int *permut = (int *) calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		permut[i] = i + 1;
	}

	getKthPermutSeq(permut, nf, n, k, 0);

	char *result = (char *) calloc(n, sizeof(char));
	for (i = 0; i < n; i++) {
		result[i] = permut[i] + '0';
	}

	free(permut);

	return result;
}
