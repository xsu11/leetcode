/*
 * MergeSortedArray.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 *
 * Assume the input arrays are both in assendant order.
 */

/*
 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

 Note:
 You may assume that nums1 has enough space (size that is greater or equal to m + n)
 to hold additional elements from nums2.
 The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
	int total = m + n - 1;
	int idx1 = m - 1;
	int idx2 = n - 1;
	while (idx1 > -1 || idx2 > -1) {
		if (idx1 < 0) {
			nums1[total] = nums2[idx2--];
		} else if (idx2 < 0) {
			nums1[total] = nums1[idx1--];
		} else if (nums1[idx1] > nums2[idx2]) {
			nums1[total] = nums1[idx1--];
		} else {
			nums1[total] = nums2[idx2--];
		}
		total--;
	}
}
