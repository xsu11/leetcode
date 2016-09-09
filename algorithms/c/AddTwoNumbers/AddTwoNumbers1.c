/*
 * AddTwoNumbers1.c
 *
 *  Created on: Aug 25, 2016
 *      Author: xinsu
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* c1 = l1;
	struct ListNode* c2 = l2;
	struct ListNode* result = NULL;
	struct ListNode** r = &result;
	int sum = 0;
	int carry = 0;

	while (c1 != NULL || c2 != NULL) {
		sum = (c1 != NULL ? c1->val : 0) + (c2 != NULL ? c2->val : 0) + carry;
		carry = sum / 10;

		struct ListNode* node = (struct ListNode*) calloc(1,
				sizeof(struct ListNode));
		node->val = sum % 10;

		*r = node;
		r = &node->next;

		// move cursors
		if (c1 != NULL) {
			c1 = c1->next;
		}

		if (c2 != NULL) {
			c2 = c2->next;
		}
	}

	if (carry > 0) {
		struct ListNode* node = (struct ListNode*) calloc(1,
				sizeof(struct ListNode));
		node->val = carry;
		*r = node;
	}

	return result;
}
