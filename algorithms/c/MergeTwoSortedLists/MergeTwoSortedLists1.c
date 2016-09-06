/*
 * MergeTwoSortedLists1.c
 *
 *  Created on: Sep 02, 2016
 *      Author: xinsu
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
 *
 * Assume the input Linked lists are both sorted in assendent order.
 */
#include <stdio.h>
#include <limits.h>

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode *result = NULL;
	struct ListNode **r = &result;
	struct ListNode *p1 = l1;
	struct ListNode *p2 = l2;

	while (p1 != NULL || p2 != NULL) {
		if (p1 == NULL) {
			// copy l2's remain nodes
			while (p2 != NULL) {
				// create node
				struct ListNode *node = (struct ListNode *) calloc(1,
						sizeof(struct ListNode));
				node->val = p2->val;
				*r = node;
				r = &node->next;

				p2 = p2->next;
			}
		} else if (p2 == NULL) {
			// copy l1's remain nodes
			while (p1 != NULL) {
				// create node
				struct ListNode *node = (struct ListNode *) calloc(1,
						sizeof(struct ListNode));
				node->val = p1->val;
				*r = node;
				r = &node->next;

				p1 = p1->next;
			}
		} else {
			// create node
			struct ListNode *node = (struct ListNode *) calloc(1,
					sizeof(struct ListNode));

			if (p1->val <= p2->val) {
				node->val = p1->val;
				p1 = p1->next;
			} else {
				node->val = p2->val;
				p2 = p2->next;
			}

			*r = node;
			r = &node->next;
		}
	}

	return result;
}
