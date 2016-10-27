/*
 * RotateArray2.c
 *
 *  Created on: Sep 14, 2016
 *      Author: xinsu
 *
 * Brutal force: each time rotate one element.
 * Use an temp int to store the rotating value, then move the rest elements one spot next.
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
	if (nums == NULL || numsSize <= 1 || k == 0 || numsSize == k) {
		return;
	}

	if (k > numsSize) {
		k %= numsSize;
	}

	int t = 0;
	for (; k > -1; k--) {
		t = nums[numsSize - 1];
		for (int i = numsSize - 2; i > -1; i--) {
			nums[i + 1] = nums[i];
		}
	}
	nums[0] = t;
}
