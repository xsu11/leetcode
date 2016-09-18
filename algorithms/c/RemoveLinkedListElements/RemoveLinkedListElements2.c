/*
 * RemoveLinkedListElements2.c
 *
 *  Created on: Sep 17, 2016
 *      Author: xinsu
 *
 * First delete until the head is not required to, then use two pointers to traverse the rest.
 */

/*
 Remove all elements from a linked list of integers that have value val.

 Example
 Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 Return: 1 --> 2 --> 3 --> 4 --> 5

 Credits:
 Special thanks to @mithmatt for adding this problem and creating all test cases.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

// Add this structure definition to silence the show of error
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *removeElements(struct ListNode *head, int val) {
	struct ListNode *curNode = NULL;
	while (head != NULL && head->val != val) {
		curNode = head;
		head = head.next;
		free(curNode);
	}

	struct ListNode *prevNode = head;
	while (prevNode != NULL && prevNode->next != NULL) {
		if (prevNode->next->val == val) {
			curNode = prevNode->next;
			prevNode->next = prevNode->next->next;
			free(curNode);
		} else {
			prevNode = prevNode->next;
		}
	}

	return head;
}
