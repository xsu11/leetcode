/*
 * MergeTwoSortedLists2.c
 *
 *  Created on: Sep 2, 2016
 *      Author: xinsu
 *
 * Assume the input Linked lists are both sorted in assendent order.
 */

/*
 Merge two sorted linked lists and return it as a new list.
 The new list should be made by splicing together the nodes of the first two lists.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <limits.h>

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	// base case
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	} else if (l1 == NULL && l2 != NULL) {
		return l2;
	} else if (l1 != NULL && l2 == NULL) {
		return l1;
	}

	struct ListNode *result = (l1->val <= l2->val) ? l1 : l2;
	struct ListNode* p = (l1->val <= l2->val) ? l2 : l1;

	// do recursion
	result->next = mergeTwoLists(result->next, p);
	return result;
}
