/*
 * IntersectionOfTwoLinkedLists3.c
 *
 *  Created on: Sep 12, 2016
 *      Author: xinsu
 *
 * Reference: https://discuss.leetcode.com/topic/45769/c-solution-using-xor-trick
 *
 * Start from this:
 *
 *        (p) a1 → a2
 *                    ↘
 *                      X → c1 → c2
 *                    ↗
 *   (q) b1 → b2 → b3
 *
 * follow p, reversing list as you go:
 *
 *           a1 ← a2
 *                   ↖
 *                     X ← c1 ← c2 (p)
 *                   ↗
 *  (q) b1 → b2 → b3
 *
 * now follow q, reverse list:
 *
 *       (q) a1 → a2
 *                   ↘
 *                     X ← c1 ← c2 (p)
 *                   ↙
 *      b1 ← b2 ← b3
 *
 * then follow p again:
 *
 *       (q) a1 → a2
 *                   ↘
 *                     X → c1 → c2
 *                   ↗
 *  (p) b1 → b2 → b3
 *
 * Notice that p and q are swapped, but the list structure is back to what it was in the beginning.
 *
 * Now the key observation: each node in branches a, b and c has been visited exactly twice,
 * while X has been visited three times.
 * We can thus use the well known trick: keep an accumulator and XOR it to each address we visit along the way.
 * In the end, the accumulator will contain the address of the only node visited an odd number of times, that is X.
 *
 * What if the lists don't meet?
 * In that case we have already reversed p twice changing it back to its initial state,
 * so we only need to reverse q a second time as well and return null.
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
#include <stdint.h>

// Add this structure definition to silence the show of error.
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *reverseListAndXOR(struct ListNode *curNode, uintptr_t *result) {
	struct ListNode *prevNode = NULL;
	struct ListNode *nextNode = NULL;

	while (curNode != NULL) {
		// Quoted from "K & R - 2.9":
		// Bitwise operators may only be applied to integral oprands,
		// that is, char, short, int and long, whether signed or unsigned.
		*result ^= (uintptr_t) curNode;
		nextNode = curNode->next;
		curNode->next = prevNode;
		prevNode = curNode;
		curNode = nextNode;
	}

	return prevNode;
}

struct ListNode *getIntersectionNode(struct ListNode *headA,
		struct ListNode *headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}

	uintptr_t result = 0l;
	struct ListNode *curA = headA;
	struct ListNode *curB = headB;

	curA = reverseListAndXOR(curA, &result);
	curB = reverseListAndXOR(curB, &result);
	curA = reverseListAndXOR(curB, &result);

	if (curA == headA && curB == headB) {
		return NULL;
	}

	return (struct ListNode *) result;
}
