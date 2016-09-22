/*
 * PalindromeLinkedList1.c
 *
 *  Created on: Sep 21, 2016
 *      Author: xinsu
 *
 * Reverse the first half of the linked list and check (undo reverse when checking). O(n) time and O(1) space
 */

/*
 Given a singly linked list, determine if it is a palindrome.

 Follow up:
 Could you do it in O(n) time and O(1) space?
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

bool isPalindrome(struct ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}

	/*
	 * Initial state:
	 *
	 *  p   t     n
	 *  |   |     |
	 *      () -> () -> () -> () -> () -> ...
	 *      |
	 *      r
	 */

	struct ListNode *turtle = head;
	struct ListNode *rabbit = head;
	struct ListNode *prevNode = NULL; // turtle's previous node
	struct ListNode *nextNode = head->next; // turtle's next node

	/*
	 * Each time after we reverse a node:
	 *
	 *                  p    t     n
	 *                  |    |     |
	 *  <- () <- ... <- ()   () -> () -> ... -> () -> ...
	 */

	while (rabbit != NULL && rabbit->next != NULL) {
		rabbit = rabbit->next->next;

		// reverse
		turtle->next = prevNode; // reverse turtle's pointer
		prevNode = turtle; // prevNode points to current turtle
		turtle = nextNode; // move turtle forward
		nextNode = turtle->next; // move nextNode to turtle's next node
	}

	/*
	 * After the rabbit reaches the end (either points to NULL, or points to the last node):
	 *
	 * 1. Points to NULL (even nodes, use six nodes as example):
	 *                 p    t     n
	 *                 |    |     |
	 *  <- () <- () <- ()   () -> () -> () ->
	 *                                        |
	 *                                        r
	 *
	 * 2. Points to the last node (odd nodes, use five nodes as example):
	 *           p    t     n
	 *           |    |     |
	 *  <- () <- ()   () -> () -> () ->
	 *                            |
	 *                            r
	 */

	if (rabbit == NULL) {
		// there are even nodes
		rabbit = turtle;
	} else if (rabbit->next == NULL) {
		// else there are odd nodes
		rabbit = nextNode;
	}

	nextNode = turtle;
	turtle = prevNode;
	prevNode = nextNode;
	nextNode = turtle->next;

	/*
	 * Before checking if the list is palindrome, put all the pointers in place:
	 *
	 * 1. even nodes, use four six nodes as example:
	 *           n     t    p
	 *           |     |    |
	 *  <- () <- () <- ()   () -> () -> () ->
	 *                      |
	 *                      r
	 *
	 * 2. odd nodes, use five nodes as example:
	 *     n     t    p
	 *     |     |    |
	 *  <- () <- ()   () -> () -> () ->
	 *                      |
	 *                      r
	 */

	while (turtle != NULL && rabbit != NULL) {
		if (turtle->val != rabbit->val) {
			return false;
		}

		rabbit = rabbit->next;

		// undo reverse, the same operatiosn as reverse
		turtle->next = prevNode;
		prevNode = turtle;
		turtle = nextNode;

		// do not set nextNode when coming to the last node
		if (turtle != NULL) {
			nextNode = turtle->next;
		}
	}

	return true;
}
