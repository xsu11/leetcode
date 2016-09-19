/*
 * ReverseLinkedList1.c
 *
 *  Created on: Sep 19, 2016
 *      Author: xinsu
 *
 * Iterative solution: From 160. Intersection of Two Linked Lists
 */

/*
 Reverse a singly linked list.

 click to show more hints.

 Hint:
 A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

// Add this structure definition to silence the show of error
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *prevNode = NULL;
	struct ListNode *nextNode = NULL;

	while (head != NULL) {
		// Quoted from "K & R - 2.9":
		// Bitwise operators may only be applied to integral oprands,
		// that is, char, short, int and long, whether signed or unsigned.
		nextNode = head->next;
		head->next = prevNode;
		prevNode = head;
		head = nextNode;
	}

	return prevNode;
}
