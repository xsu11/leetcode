/*
 * RotateArray3_Juggling.c
 *
 *  Created on: Sep 14, 2016
 *      Author: xinsu
 *
 * TO DO - Juggling: Reference: Programming Pearls (2nd Ed), 2.3
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

//int gcd(int i, int j) {
//	while (i != j) {
//		if (i > j) {
//			i -= j;
//		} else {
//			j -= i;
//		}
//	}
//
//	return i;
//}

// iterative version of gcd
//int gcd(int a, int b) {
//	while (b != 0) {
//		int c = a % b;
//		a = b;
//		b = c;
//	}
//
//	return a;
//}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

void rotate(int *nums, int numsSize, int k) {
	if (nums == NULL || numsSize <= 1 || k == 0 || numsSize == k) {
		return;
	}

	if (k > numsSize) {
		k = numsSize - k % numsSize;
	} else {
		k = numsSize - k;
	}

	for (int i = 0; i < gcd(k, numsSize); i++) {
		int t = nums[i];
		int this = i;
		int next = this + k;
		if (next >= numsSize) {
			next -= numsSize;
		}

		int j = 0;
		while (next != i) {
			nums[this] = nums[next];

			this = next;
			next += k;
			if (next >= numsSize) {
				next -= numsSize;
			}
		}
		nums[this] = t;
	}
}
