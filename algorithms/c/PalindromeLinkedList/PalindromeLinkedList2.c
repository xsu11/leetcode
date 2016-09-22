/*
 * PalindromeLinkedList2.c
 *
 *  Created on: Sep 22, 2016
 *      Author: xinsu
 *
 * Use an array of int to store all vals. O(n) time and O(n) space.
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
#include <stdlib.h>
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

	struct ListNode *curNode = head;
	int length = 1;
	while ((curNode = curNode->next) != NULL) {
		length++;
	}

	int *a = (int *) calloc(length, sizeof(int));

	curNode = head;
	int i = 0;
	for (i = 0; i < length; i++, curNode = curNode->next) {
		a[i] = curNode->val;
	}

	for (i = 0; i < length / 2; i++) {
		if (a[i] != a[length - 1 - i]) {
			return false;
		}
	}

	free(a);
	return true;
}
