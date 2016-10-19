/*
 * SinglyLinkedList.c
 *
 *  Created on: Oct 18, 2016
 *      Author: xinsu
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*** Singly Linked List structure definition ***/
struct SllNode {
	int info;
	void *data;
	struct SllNode *next;
};

struct Sll {
	int size;
	struct SllNode *head;
	struct SllNode *tail;
};
/*** Singly Linked List structure definition end ***/

/*** Singly Linked List operations definition ***/
struct Sll *create() {
	struct Sll *sll = (struct Sll *) calloc(1, sizeof(struct Sll));
	return sll;
}

void destroy(struct Sll *sll) {
	if (sll != NULL) {
		if (sll->head != NULL) {
			struct SllNode *curNode = sll->head;
			while (sll->head != NULL) {
				sll->head = sll->head->next;
				free(curNode);
				curNode = sll->head;
			}
		}
		free(sll);
	}
}

bool add(struct Sll *sll, int idx, void *data, int info) {
	if (sll == NULL || idx < 0 || idx > sll->size) {
		return false;
	}

	// alloc memory for new node
	struct SllNode *node = (struct SllNode *) calloc(1, sizeof(struct SllNode));
	node->data = data;
	node->info = info;

	if (sll->size == 0) {
		sll->head = node;
		sll->tail = node;
	} else {
		if (idx == 0) {
			node->next = sll->head;
			sll->head = node;
		} else if (idx == sll->size) {
			sll->tail->next = node;
			sll->tail = node;
		} else {
			// move curNode to the (idx - 1)-th node in the SLL
			struct SllNode *curNode = sll->head;
			for (int i = 0; i < idx; i++) {
				curNode = curNode->next;
			}

			// add node
			node->next = curNode->next;
			curNode->next = node;
		}
	}

	sll->size++;

	return true;
}

void *delete(struct Sll *sll, int idx, int *info) {
	if (sll == NULL || sll->size == 0 || idx < 0 || idx > sll->size - 1) {
		return NULL;
	}

	struct SllNode *node = NULL;

	if (sll->size == 1) {
		node = sll->head;
		sll->head = NULL;
		sll->tail = NULL;
	} else {
		// sll->size > 1
		if (idx == 0) {
			node = sll->head;
			sll->head = sll->head->next;
		} else {
			// move prevNode to the (idx - 1)-th node in the SLL
			struct SllNode * prevNode = sll->head;
			for (int i = 1; i < idx; i++) {
				prevNode = prevNode->next;
			}
			node = prevNode->next;

			// delete node
			prevNode->next = node->next;

			if (idx == sll->size - 1) {
				sll->tail = prevNode;
			}
		}
	}

	void *data = node->data;
	if (info != NULL) {
		*info = node->info;
	}

	sll->size--;
	free(node);

	return data;
}

bool exists(struct Sll *sll, void *d, int len,
		int (*compar)(const void *a, const void *b, int length)) {
	if (sll == NULL || d == NULL || compar == NULL) {
		return false;
	}

	struct SllNode *curNode = sll->head;
	while (curNode != NULL) {
		if (compar(curNode->data, d, len)) {
			return true;
		}
		curNode = curNode->next;
	}

	return false;
}
/*** Singly Linked List operations definition end ***/
