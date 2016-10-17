/*
 * NextPermutation.c
 *
 *  Created on: Oct 17, 2016
 *      Author: xinsu
 */

/*
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

 If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

 The replacement must be in-place, do not allocate extra memory.

 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1
 */

#include <stdio.h>

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void reverseArray(int *nums, int numsSize) {
	for (int i = 0; i < numsSize / 2; i++) {
		int j = numsSize - 1 - i;
		swap(nums + i, nums + numsSize - 1 - i);
	}
}

void nextPermutation(int* nums, int numsSize) {
	int i = numsSize - 1;
	while (i > 0 && nums[i - 1] >= nums[i]) {
		i--;
	}

	int j = -1;

	if (i > 0) {
		j = i - 1;
		while (i < numsSize && nums[i] > nums[j]) {
			i++;
		}

		// swap nums[j] and nums[i - 1]
		swap(nums + j, nums + i - 1);
	}

	reverseArray(nums + j + 1, numsSize - j - 1);
}
