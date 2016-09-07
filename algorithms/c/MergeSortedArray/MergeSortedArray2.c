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

/*
 * Store all existed elements from nums1 (existed elements length = m) and nums2 (length = n)
 * to nums1 (total length = n), start from the end of both arrays.
 *
 * Consider two cases: store an int from nums1 (index is n1) into nums1 (index is total),
 * 					or store an int from nums2 (index is n2) into nums1 (index is total).
 *
 * First case: store int from nums1: 1. n1 >= 0 && n2 >= 0 && nums1[n1] >= nums2[n2]
 * 								action: nums1[total] = nums1[n1], then n1-- and total--
 * 								or   2. n1 >= 0 && n2 < 0
 * 								action: nothing
 * Second case: store int from nums2: 3. n1 >= 0 && n2 >= 0 && nums1[n1] < nums2[n2]
 * 								action: nums1[total] = nums2[n2], then n2-- and total--
 * 								or    4. n1 < 0 && n2 >= 0
 * 								action: nums1[total] = nums2[n2], then n2-- and total--
 *
 * For the 2nd condition, there is no need to do anything,
 * because that is when all elements in nums2 has been stored into nums1.
 *
 * For the 1st, 3rd and 4th condition, there is one common condition: n2 >= 0:
 * 		For 3rd and 4th condition the action is the same: store from nums2, so combine these two.
 * 		For else condtion, that is 1st, store from nums1.
 *
 */

#include <stdio.h>

void merge(int* nums1, int m, int* nums2, int n) {
	int total = m + n - 1;
	int n1 = m - 1;
	int n2 = n - 1;
	while (n2 > -1) {
		if (n1 < 0 || nums1[n1] <= nums2[n2]) {
			nums1[total--] = nums2[n2--];
		} else {
			nums1[total--] = nums1[n1--];
		}
	}
}
