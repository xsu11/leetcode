/*
 * RotateArray4.c
 *
 *  Created on: Sep 14, 2016
 *      Author: xinsu
 *
 * Reverse: a' is reverse of a. (a'b')' = ba
 * ab -> a' -> a'b' -> ba
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

void reverseArray(int *a, int idxBegin, int idxEnd) {
	int t = 0;
	for (; idxBegin < idxEnd; idxBegin++, idxEnd--) {
		t = a[idxBegin];
		a[idxBegin] = a[idxEnd];
		a[idxEnd] = t;
	}
}

void rotate(int *nums, int numsSize, int k) {
	if (nums == NULL || numsSize <= 1 || k == 0 || numsSize == k) {
		return;
	}

	if (k > numsSize) {
		k %= numsSize;
	}

	reverseArray(nums, 0, numsSize - k - 1);
	reverseArray(nums, numsSize - k, numsSize - 1);
	reverseArray(nums, 0, numsSize - 1);
}
