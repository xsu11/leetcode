/*
 * RemoveNthNodeFromEndOfList.c
 *
 *  Created on: Aug 31, 2016
 *      Author: xinsu
 */

/*
 Given a linked list, remove the nth node from the end of list and return its head.

 For example,

 Given linked list: 1->2->3->4->5, and n = 2.

 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *curNode = head;
	struct ListNode *nNode = head;
	struct ListNode *nPrevNode = head;

	int i = 0;
	for (i = 0; i < n; i++) {
		curNode = curNode->next;
	}

	// as the input n is always valid
	// if curNode == NULL after moving forward n nodes, then the to-be-deleted node is the head
	if (curNode == NULL) {
		head = head->next;
		return head;
	}

	while (curNode != NULL) {
		nPrevNode = nNode;
		nNode = nNode->next;
		curNode = curNode->next;
	}

	// remove node
	nPrevNode->next = nNode->next;
	return head;
}
