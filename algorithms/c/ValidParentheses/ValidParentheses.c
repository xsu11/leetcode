/*
 * ValidParentheses.c
 *
 *  Created on: Sep 02, 2016
 *      Author: xinsu
 */

/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
	int size;
	int length;
	char *data;
};

char top(struct Stack *stack) {
	if (stack->size <= 0) {
		return NULL;
	}

	return stack->data[stack->size - 1];
}

bool push(struct Stack *stack, char s) {
	if (stack->size >= stack->length) {
		return false;
	}

	stack->data[stack->size] = s;
	stack->size++;

	return true;
}

char pop(struct Stack *stack) {
	if (stack->size <= 0) {
		return NULL;
	}

	char s = stack->data[stack->size-- - 1];
	return s;
}

bool isValid(char* s) {
	int length = strlen(s);

	// init stack
	struct Stack *stack = (struct Stack *) calloc(1, sizeof(struct Stack));
	stack->length = length;
	stack->data = (char *) calloc(length, sizeof(char));

	int i = 0;
	for (i = 0; i < length; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			push(stack, s[i]);
		} else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			char t = top(stack);
			if ((t == '(' && s[i] == ')') || (t == '[' && s[i] == ']')
					|| (t == '{' && s[i] == '}')) {
				pop(stack);
			} else {
				return false;
			}
		} else {
			return false;
		}
	}

	if (stack->size > 0) {
		return false;
	}

	return true;
}
