/*
 * Permutations2.c
 *
 *  Created on: Oct 20, 2016
 *      Author: xinsu
 * 
 * Iteration
 */

/*
 Given a collection of distinct numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
 ]
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int **permute(int *nums, int numsSize, int *returnSize) {
	if (nums == NULL || numsSize < 1) {
		return NULL;
	}

	// get returnSize: returnSize = numsSize!
	int i = 2;
	for (*returnSize = 1; i < numsSize + 1; i++) {
		*returnSize *= i;
	}

	// alloc memory for result array
	int **results = (int **) calloc(*returnSize, sizeof(int *));
	for (i = 0; i < *returnSize; i++) {
		results[i] = (int *) calloc(numsSize, sizeof(int));
	}

	int step = *returnSize;
	results[0][0] = nums[0]; // the root of the tree

	// each loop of this for is fill one level
	// i: index of nums, also the i-th level below the root,
	// also the index of the result array to be filled
	// 1 <= i < numsSize
	for (i = 1; i < numsSize; i++) {
		int prevStep = step;
		step = step / (i + 1);

		// each loop of this for is filling all children of one node of previous level
		// j: first index of each node of previous level
		// 0 <= j < *returnSize
		for (int j = 0; j < *returnSize; j += prevStep) {
			// p: the index that the new value is stored
			// when the pos needs to be filled is equal to p, decrease p by 1,
			// 0 <= p <= i - 1
			int p = i - 1;

			// each loop of this for is filling one node of this level
			// k: first index of each node of this level
			// whose parent is the j-th node of previous level
			// j <= k < j + prevStep
			for (int k = j; k < j + prevStep; k += step) {
				if (k == j) {
					// this is the first node of i-th node of j-th node from previous level
					// simply store the new element in the next pos in the array,
					// which is the i-th pos
					results[k][i] = nums[i]; // new element is stored at the i + 1
				} else {
					// for other nodes those after the first one:
					// copy the new element into every pos before i-th

					// r: the index of results[j], start from 0,
					// when copied an element from result[j], increase r by 1
					// 0 <= r <= i - 1
					int r = 0;

					// each loop of this for is fill pos in the node
					// q: the index of results[k], each copy increase q by 1
					// 0 <= q <= i
					for (int q = 0; q < i + 1; q++) {
						if (q == p) {
							// now this is the pos for the new element,
							// store the new element to results[k]
							results[k][p--] = nums[i];
						} else {
							// this is the pos to store the element from results[j] at index r
							results[k][q] = results[j][r++];
						}
					}
				}
			}
		}
	}

	return results;
}
