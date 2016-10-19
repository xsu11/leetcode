/*
 * GenerateParentheses1.c
 *
 *  Created on: Oct 11, 2016
 *      Author: xinsu
 *
 * Recursion
 */

/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*** Doubly Linked List structure definition ***/
struct DllNode {
	int info;
	void *data;
	struct DllNode *prev;
	struct DllNode *next;
};

struct Dll {
	int size;
	struct DllNode *head;
	struct DllNode *tail;
};
/*** Doubly Linked Lis structure definition end ***/

/*** Doubly Linked Lis operations definition ***/
struct Dll *create() {
	struct Dll *dll = (struct Dll *) calloc(1, sizeof(struct Dll));
	return dll;
}

void destroy(struct Dll *dll) {
	if (dll != NULL) {
		if (dll->head != NULL) {
			struct DllNode *curNode = dll->head;
			while (dll->head != NULL) {
				dll->head = dll->head->next;
				free(curNode);
				curNode = dll->head;
			}
		}
		free(dll);
	}
}

bool add(struct Dll *dll, int idx, void *data, int info) {
	if (dll == NULL || idx < 0 || idx > dll->size) {
		return false;
	}

	// alloc memory for new node
	struct DllNode *node = (struct DllNode *) calloc(1, sizeof(struct DllNode));
	node->data = data;
	node->info = info;

	if (dll->size == 0) {
		dll->head = node;
		dll->tail = node;
	} else {
		if (idx == 0) {
			node->next = dll->head;
			dll->head->prev = node;
			dll->head = node;
		} else if (idx == dll->size) {
			node->prev = dll->tail;
			dll->tail->next = node;
			dll->tail = node;
		} else {
			// move curNode to the idx-th node in the DLL
			struct DllNode *curNode = dll->head;
			for (int i = 0; i < idx + 1; i++) {
				curNode = curNode->next;
			}

			node->next = curNode;
			node->prev = curNode->prev;
			curNode->prev->next = node;
			curNode->prev = node;
		}
	}

	dll->size++;

	return true;
}

void *delete(struct Dll *dll, int idx, int *info) {
	if (dll == NULL || dll->size == 0 || idx < 0 || idx > dll->size - 1) {
		return NULL;
	}

	struct DllNode *node = NULL;

	if (dll->size == 1) {
		node = dll->head;
		dll->head = NULL;
		dll->tail = NULL;
	} else {
		if (idx == 0) {
			node = dll->head;
			dll->head = dll->head->next;
			dll->head->prev = NULL;
		} else if (idx == dll->size - 1) {
			node = dll->tail;
			dll->tail = dll->tail->prev;
			dll->tail->next = NULL;
		} else {
			node = dll->head;
			for (int i = 0; i < idx + 1; i++) {
				node = node->next;
			}

			node->prev->next = node->next;
			node->next->prev = node->prev;
		}
	}

	void *data = node->data;
	if (info != NULL) {
		*info = node->info;
	}

	dll->size--;
	free(node);

	return data;
}

bool exists(struct Dll *dll, void *d, int len,
		int (*compar)(const void *a, const void *b, int length)) {
	if (dll == NULL || d == NULL || compar == NULL) {
		return false;
	}

	struct DllNode *curNode = dll->tail;
	while (curNode != NULL) {
		if (compar(curNode->data, d, len)) {
			return true;
		}
		curNode = curNode->prev;
	}

	return false;
}
/*** Doubly Linked Lis operations definition end ***/

/*
 left: the remaining left parens needs to add
 right: the remaining right parens needs to add
 dll: an doubly linked list to store the results
 s: the string used to store current result
 idx: the index in s which to be filled
 */
void genParens(int left, int right, struct Dll *dll, char *s, int idx) {
	// base case
	if (left == 0 && right == 0) {
		// make a copy of s and add it to dll
		// when the code comes to the base case, idx is equal to the length of s
		char *r = (char *) calloc(idx, sizeof(char));
		strcpy(r, s);
		add(dll, dll->size, (void *) r, NULL);
		return;
	}

	if (left < right) {
		if (left > 0) {
			// add left paren to r
			s[idx] = '(';
			genParens(left - 1, right, dll, s, idx + 1);
		}
		if (right > 0) {
			// add right paren to r
			s[idx] = ')';
			genParens(left, right - 1, dll, s, idx + 1);
		}
	} else {
		/*
		 The condition here is: left = right && left > 0 && right > 0

		 The reason is:
		 each time when left < right, we at most call once genParens passing right - 1,
		 then inside this genParens, right is at most the same as left, that is right >= left;
		 if right > left, then the code keep calling genParens passing right - 1,
		 else if right = left, then the coe comes here to call genParens passing left - 1,
		 which make the new left is smaller than new right
		 */

		// add left paren to r
		s[idx] = '(';
		genParens(left - 1, right, dll, s, idx + 1);
	}
}

char **generateParenthesis(int n, int *returnSize) {
	if (n < 1) {
		*returnSize = 0;
		return NULL;
	}

	// create dll and the repeatedly used string for the recursion
	struct Dll *dll = create();
	char *s = (char *) calloc(n * 2 + 1, sizeof(char));

	// call the recursive function
	genParens(n, n, dll, s, 0);

	// alloc memory for results array of strings and store results from dll
	*returnSize = dll->size;
	char **results = (char **) calloc(*returnSize, sizeof(char *));
	struct DllNode *curNode = dll->head;
	int i = 0;
	while (curNode != NULL) {
		results[i++] = (char *) curNode->data;
		curNode = curNode->next;
	}

	destroy(dll);
	free(s);

	return results;
}
