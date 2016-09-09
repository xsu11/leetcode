/*
 * AddTwoNumbers2.c
 *
 *  Created on: Aug 25, 2016
 *      Author: xinsu
 *
 * This solution won't survive when the number formed by linked list exceeds INT_MAX
 */

/*
 You are given two linked lists representing two non-negative numbers.
 The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

unsigned long power(int base, int x) {
	int i = 0;
	unsigned long result = 1;
	for (i = 0; i < x; i++) {
		result *= base;
	}
	return result;
}

unsigned long decoding(struct ListNode* l) {
	unsigned long result = 0;
	unsigned long i = 0;
	struct ListNode *c = l;

	while (c != NULL) {
		result += power(10, i++) * c->val;
		c = c->next;
	}

	return result;
}

struct ListNode* encoding(unsigned long n) {
	struct ListNode *result = calloc(1, sizeof(struct ListNode));
	struct ListNode *r = result;
	unsigned long i = n;
	while (i != 0) {
		r->val = i % 10;
		i /= 10;
		if (i != 0) {
			r->next = calloc(1, sizeof(struct ListNode));
			r = r->next;
		}
	}

	return result;
}

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
	unsigned long n1 = decoding(l1);
	unsigned long n2 = decoding(l2);
	return encoding(n1 + n2);
}
