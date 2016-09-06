/*
 * RemoveDuplicatesFromSortedList1.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 */

/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.

 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	struct ListNode *curNode = head->next;
	struct ListNode *prevNode = head;
	while (curNode != NULL) {
		if (curNode->val == prevNode->val) {
			prevNode->next = curNode->next;
			// Do we need to free the deleted node?
		} else {
			prevNode = curNode;
		}
		curNode = curNode->next;
	}

	return head;
}
