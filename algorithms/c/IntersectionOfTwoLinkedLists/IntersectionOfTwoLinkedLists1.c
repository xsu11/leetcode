/*
 * IntersectionOfTwoLinkedLists1.c
 *
 *  Created on: Sep 12, 2016
 *      Author: xinsu
 *
 * A:                         a1 → a2 → ... → ap
 *                                             ↘
 *                                              d1 → d2 → ... → dr → NULL
 *                                             ↗
 * B:  b1 → b2 → ... → bq  →  c1 → c2 → ... → cp
 */

/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 * 					  ↘
 * 						c1 → c2 → c3
 * 					  ↗
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * Credits:
 * Special thanks to @stellari for adding this problem and creating all test cases.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

// Add this structure definition to silence the show of error.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA,
		struct ListNode *headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}

	struct ListNode *curA = headA;
	struct ListNode *curB = headB;

	while (curA != curB) {
		curA = (curA == NULL) ? headB : curA->next;
		curB = (curB == NULL) ? headA : curB->next;
	}

	return curA;
}
