/*
 * SearchForRange.c
 *
 *  Created on: Oct 17, 2016
 *      Author: xinsu
 */

/*
 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * void *bsearch(const void *key,                               // pointer to the key to be compared
 * 				 const void *base,                              // array
 * 				 size_t nel,                                    // number of elements in the array
 * 				 size_t width,                                  // width of element in the array
 * 				 int (*compar)(const void *, const void *));    // comparison function
 */

int compar(const void *a, const void *b) {
	return *((int *) a) - *((int *) b);
}

int *searchRange(int *nums, int numsSize, int target, int *returnSize) {
	if (nums == NULL || numsSize < 0 || returnSize == NULL) {
		return NULL;
	}

	*returnSize = 2;
	int *result = (int *) calloc(*returnSize, sizeof(int));
	result[0] = -1;
	result[1] = -1;

	// search for left boundry
	int *p = NULL;
	size_t count = (size_t) numsSize;
	while ((p = bsearch(&target, (void *) nums, count, sizeof(int), compar))
			!= NULL) {
		result[0] = p - nums;
		count = result[0];
	}

	// search for right boundry
	p = nums;
	count = (size_t) numsSize;
	while ((p = bsearch(&target, (void *) p, count, sizeof(int), compar))
			!= NULL) {
		result[1] = p++ - nums;
		count = numsSize - 1 - result[1];
	}

	return result;
}
