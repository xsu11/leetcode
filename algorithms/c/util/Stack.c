/*
 * Stack.c
 *
 *  Created on: Sep 17, 2016
 *      Author: xinsu
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*** Stack structure definition ***/
struct StackNode {
	int info;
	void *data;
	struct StackNode *next;
};

struct Stack {
	int size;
	struct StackNode *head;
};
/*** Stack structure definition end ***/

/*** Stack operations definition ***/
struct Stack *create() {
	struct Stack *stack = (struct Stack *) calloc(1, sizeof(struct Stack));
	return stack;
}

void destroy(struct Stack *stack) {
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

struct StackNode *peak(struct Stack *stack) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	return stack->head;
}

bool push(struct Stack *stack, void *data, int info) {
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

void *pop(struct Stack *stack, int *info) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	struct StackNode *node = stack->head;
	void *data = node->data;
	if (info != NULL) {
		*info = node->info;
	}

	stack->head = stack->head->next;
	stack->size--;
	free(node);

	return data;
}
/*** Stack operations definition end ***/
