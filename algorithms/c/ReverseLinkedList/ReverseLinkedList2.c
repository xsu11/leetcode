/*
 * ReverseLinkedList2.c
 *
 *  Created on: Sep 19, 2016
 *      Author: xinsu
 *
 * Tail recursive solution
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

struct ListNode *reverseList(struct ListNode *head) {
	// base case
	if (head == NULL || head->next == NULL) {
		return head;
	}

	// do recursion
	struct ListNode *newHead = reverseList(head->next);

	head->next->next = head;
	head->next = NULL;

	return newHead;

}
