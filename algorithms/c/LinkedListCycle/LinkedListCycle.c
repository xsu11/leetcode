/*
 * LinkedListCycle.c
 *
 *  Created on: Sep 12, 2016
 *      Author: xinsu
 * 
 * This solutions uses racing.
 * Another solution is to use a hash table to record all passed nodes' values.
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
		// if the rabbit catches up with the turtle, it means there is a circle in the list.
		if (rabbit == turtle) {
			return true;
		}

		turtle = turtle->next;
		rabbit = rabbit->next->next;

	}

	// if the code comes here, it means both rabbit and turtle comes to the end of the list
	// then there is no circle
	return false;
}
