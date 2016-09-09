/*
 * StackChar.c
 *
 *  Created on: Sep 02, 2016
 *      Author: xinsu
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*** Stack structure definition ***/
struct StackChar {
	int size;
	int length;
	char *data;
};
/*** Stack structure definition end ***/

/*** Stack opeations difinition ***/
struct StackChar *create(int length) {
	if (length <= 0) {
		return NULL;
	}
	struct StackChar *stack = (struct StackChar *) calloc(1,
			sizeof(struct StackChar));
	stack->length = length;
	stack->data = (char *) calloc(length, sizeof(char));
	return stack;
}

void destroy(struct StackChar *stack) {
	if (stack != NULL) {
		if (stack->data != NULL) {
			free(stack->data);
		}
		free(stack);
	}
}

char peak(struct StackChar *stack) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	return stack->data[stack->size - 1];
}

bool push(struct StackChar *stack, char s) {
	if (stack->size >= stack->length) {
		return false;
	}

	stack->data[stack->size] = s;
	stack->size++;

	return true;
}

char pop(struct StackChar *stack) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	char s = stack->data[stack->size-- - 1];
	return s;
}
/*** Stack opeations difinition end ***/
