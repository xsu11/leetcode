/*
 * DoublyLinkedList.c
 *
 *  Created on: Oct 04, 2016
 *      Author: xinsu
 */

#include <stdio.h>
#include <stdlib.h>
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
/*** Doubly Linked List structure definition end ***/

/*** Doubly Linked List operations definition ***/
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
/*** Doubly Linked List operations definition end ***/
