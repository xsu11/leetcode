/*
 * RotateArray1.c
 *
 *  Created on: Sep 14, 2016
 *      Author: xinsu
 *
 * Use an array k length.
 */

/*
 Rotate an array of n elements to the right by k steps.

 For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

 Note:
 Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

 [show hint]

 Hint:
 Could you do it in-place with O(1) extra space?
 Related problem: Reverse Words in a String II

 Credits:
 Special thanks to @Freezen for adding this problem and creating all test cases.
 */

#include <stdio.h>

void rotate(int *nums, int numsSize, int k) {
	if (nums == NULL || numsSize <= 1 || k == 0 || k == numsSize) {
		return;
	}

	if (k > numsSize) {
		k %= numsSize;
	}

	// create an array of k length
	int a[k];

	int i = numsSize - 1;
	for (; i > numsSize - k - 1; i--) {
		a[i + k - numsSize] = nums[i];
	}

	for (; i > -1; i--) {
		nums[i + k] = nums[i];
	}

	for (i++; i < k; i++) {
		nums[i] = a[i];
	}
}
