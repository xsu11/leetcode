/*
 * SwapNodesInPairs1.c
 *
 *  Created on: Sep 03, 2016
 *      Author: xinsu
 */

/*
 Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>

struct ListNode* swapPairs(struct ListNode* head) {
	// base case
	if (head == NULL || head->next == NULL) {
		return head;
	}

	// swap Nodes
	struct ListNode* p = head->next;
	head->next = p->next;
	p->next = head;

	// do recursion
	head->next = swapPairs(head->next);
	return p;
}
