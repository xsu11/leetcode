/*
 * LinkedListCycle.c
 *
 *  Created on: Sep 12, 2016
 *      Author: xinsu
 */

/*
 Given a linked list, determine if it has a cycle in it.

 Follow up:
 Can you solve it without using extra space?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdbool.h>

// Add this structure definition to silence the show of error.
struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return false;
	}

	struct ListNode *turtle = head;
	struct ListNode *rabbit = head->next->next;

	while (rabbit != NULL && rabbit->next != NULL) {
		if (rabbit == turtle) {
			return true;
		}

		turtle = turtle->next;
		rabbit = rabbit->next->next;

	}

	return false;
}
