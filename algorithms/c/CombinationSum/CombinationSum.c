/*
 * CombinationSum.c
 *
 *  Created on: Oct 19, 2016
 *      Author: xinsu
 */

/*
 Given a set of candidate numbers (C) and a target number (T),
 find all unique combinations in C where the candidate numbers sums to T.

 The same repeated number may be chosen from C unlimited number of times.

 Note:
 All numbers (including target) will be positive integers.
 The solution set must not contain duplicate combinations.

 For example, given candidate set [2, 3, 6, 7] and target 7,
 A solution set is:
 [
 [7],
 [2, 2, 3]
 ]
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compar(const void *a, const void *b) {
	return *((int *) a) - *((int *) b);
}

int dllCompar(const void *a, const void *b, int length) {
	int *aa = (int *) a;
	int *bb = (int *) b;
	for (int i = 0; i < length; i++) {
		if (aa[i] != bb[i]) {
			return 0;
		}
	}

	return 1;
}

void getCombinationSum(int *a, int aSize, int target, struct Sll *sll,
		struct Sll *list) {
	// base case
	if (target < 0) {
		return;
	}

	if (target == 0) {
		// create a new array from list and store it into sll if it does not exist
		// store the size of the array to info in the node
		int *result = (int *) calloc(list->size, sizeof(int));
		struct SllNode *node = list->head;
		for (int i = 0; i < list->size; i++) {
			result[i] = node->info;
			node = node->next;
		}

		if (exists(sll, (void *) result, list->size, dllCompar)) {
			free(result);
		} else {
			add(sll, sll->size, (void *) result, list->size);
		}

		return;
	}

	for (int i = 0; i < aSize && a[i] <= target; i++) {
		// add this candidate to the list and call recursion
		add(list, list->size, NULL, a[i]);

		getCombinationSum(a + i, aSize - i, target - a[i], sll, list);

		// after recursion, remove the element that just added into the list
		delete(list, list->size - 1, NULL);
	}
}

/*
 * void qsort(void *base,									// array
 * 			  size_t nel,									// number of elements in the array
 * 			  size_t width,									// width of element in the array
 *			  int (*compar)(const void *, const void *));	// comparison function
 */

int **combinationSum(int *candidates, int candidatesSize, int target,
		int **columnSizes, int *returnSize) {
	if (candidates == NULL || candidatesSize < 1) {
		return NULL;
	}

	// make a copy of the input array and sort it
	int *a = (int *) calloc(candidatesSize, sizeof(int));
	int i = 0;
	for (i = 0; i < candidatesSize; i++) {
		a[i] = candidates[i];
	}
	qsort((void *) a, candidatesSize, sizeof(int), compar);

	struct Sll *sll = create();
	struct Sll *list = create();

	getCombinationSum(a, candidatesSize, target, sll, list);

	*returnSize = sll->size;
	*columnSizes = (int *) calloc(*returnSize, sizeof(int));
	int **results = (int **) calloc(*returnSize, sizeof(int *));

	struct SllNode *node = sll->head;
	for (int i = 0; i < *returnSize; i++) {
		columnSizes[0][i] = node->info;
		results[i] = (int *) node->data;
		node = node->next;
	}

	destroy(sll);
	destroy(list);

	return results;
}
