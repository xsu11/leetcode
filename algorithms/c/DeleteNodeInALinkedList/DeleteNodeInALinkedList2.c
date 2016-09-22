/*
 * DeleteNodeInALinkedList2.c
 *
 *  Created on: Sep 22, 2016
 *      Author: xinsu
 *
 * Not an actually delete, just copy all the data from next to this node and then delete next node.
 */

/*
 Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

 Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,
 the linked list should become 1 -> 2 -> 4 after calling your function.
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

void deleteNode(struct ListNode* node) {
	struct ListNode *nextNode = node->next;

	// Copy the entire value of the structure (including val and next pointer) from next node to this node.
	*node = *nextNode;

	free(nextNode);
}
