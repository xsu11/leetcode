/*
 * RemoveDuplicatesFromSortedList2.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 *
 * Tail recursion solution
 */

/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.

 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

// Add this truct definition to scient the show of error of head->next->val
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	head->next = deleteDuplicates(head->next);

	if (head->val == head->next->val) {
		head = head->next;
	}

	return head;
}
