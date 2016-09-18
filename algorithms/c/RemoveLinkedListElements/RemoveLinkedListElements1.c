/*
 * RemoveLinkedListElements1.c
 *
 *  Created on: Sep 17, 2016
 *      Author: xinsu
 *
 * Check the head at last.
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
	if (head == NULL) {
		return NULL;
	}

	struct ListNode *curNode = head->next;
	struct ListNode *prevNode = head;

	while (curNode != NULL) {
		if (curNode->val == val) {
			prevNode->next = curNode->next;
			free(curNode);
			curNode = prevNode->next;
		} else {
			prevNode = curNode;
			curNode = curNode->next;
		}
	}

	if (head->val == val) {
		curNode = head;
		head = head->next;
		free(curNode);
	}

	return head;
}
