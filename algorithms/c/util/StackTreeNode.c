/*
 * StackTreeNode.c
 *
 *  Created on: Sep 07, 2016
 *      Author: xinsu
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*** Stack structure definition ***/
struct StackNode {
	int info;
	struct TreeNode *data;
	struct StackNode *next;
};

struct StackTreeNode {
	int size;
	struct StackNode *head;
};
/*** Stack structure definition end ***/

/*** Stack operations definition ***/
struct StackTreeNode *create() {
	struct StackTreeNode *stack = (struct StackTreeNode *) calloc(1,
			sizeof(struct StackTreeNode));
	return stack;
}

void destroy(struct StackTreeNode *stack) {
	if (stack != NULL) {
		if (stack->head != NULL) {
			struct StackNode *curNode = stack->head;
			while (stack->head != NULL) {
				stack->head = stack->head->next;
				free(curNode);
				curNode = stack->head;
			}
		}
		free(stack);
	}
}

struct StackNode *peak(struct StackTreeNode *stack) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	return stack->head;
}

bool push(struct StackTreeNode *stack, struct TreeNode *data, int info) {
	if (stack == NULL) {
		return false;
	}

	// alloc memory for new node
	struct StackNode *node = (struct StackNode *) calloc(1,
			sizeof(struct StackNode));
	node->data = data;
	node->info = info;
	node->next = stack->head;
	stack->head = node;
	stack->size++;

	return true;
}

struct TreeNode *pop(struct StackTreeNode *stack, int *info) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	struct StackNode *node = stack->head;
	struct TreeNode *data = node->data;
	if (info != NULL) {
		*info = node->info;
	}
	stack->head = stack->head->next;
	stack->size--;
	free(node);
	return data;
}
/*** Stack operations definition end ***/
