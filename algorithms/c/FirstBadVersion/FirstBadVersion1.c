/*
 * FirstBadVersion1.c
 *
 *  Created on: Sep 26, 2016
 *      Author: xinsu
 *
 * Iteration
 */

/*
 You are a product manager and currently leading a team to develop a new product.
 Unfortunately, the latest version of your product fails the quality check.
 Since each version is developed based on the previous version, all the versions after a bad version are also bad.

 Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
 which causes all the following ones to be bad.

 You are given an API bool isBadVersion(version) which will return whether version is bad.
 Implement a function to find the first bad version. You should minimize the number of calls to the API.

 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
	int first = 1;
	int last = n;

	while (first < last) {
		int mid = first + (last - first) / 2;

		if (isBadVersion(mid) == true) {
			if (isBadVersion(mid - 1) == false) {
				return mid;
			} else {
				// go to lower side
				last = mid - 1;
			}
		} else {
			// go to higher side
			first = mid + 1;
		}
	}

	return first;
}
