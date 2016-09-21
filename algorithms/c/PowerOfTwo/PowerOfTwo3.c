/*
 * PowerOfTwo3.c
 *
 *  Created on: Sep 20, 2016
 *      Author: xinsu
 *
 * n & (-n) gets the integer with the right most 1 in n (suppose n > 0)
 *
 * n's true code is :            0x...x10...0
 * n's ones-complement code is:  0x...x10...0
 * n's complemental code is:     0x...x10...0
 *
 * -n's true code is:            1x...x10...0
 * -n's ones-complement code is: 1y...y01...1
 * -n's complemental code is:    1y...y10...0
 *
 * n & -n is: 0x...x10...0  &  1y...y10...0  =  00...010...0
 */

/*
 Given an integer, write a function to determine if it is a power of two.

 Credits:
 Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
	return n > 0 && (n & (-n)) == n;
}
