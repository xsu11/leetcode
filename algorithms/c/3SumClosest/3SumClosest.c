/*
 * 3SumClosest.c
 *
 *  Created on: Oct 04, 2016
 *      Author: xinsu
 */

/*
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 Return the sum of the three integers. You may assume that each input would have exactly one solution.

 For example, given array S = {-1 2 1 -4}, and target = 1.

 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

bool exists(struct Dll *dll, void *d,
		int (*compar)(const void *a, const void *b, int length)) {
	if (dll == NULL || d == NULL || compar == NULL) {
		return false;
	}

	struct DllNode *curNode = dll->tail;
	while (curNode != NULL) {
		if (compar(curNode->data, d, 3)) {
			return true;
		}
		curNode = curNode->prev;
	}

	return false;
}
/*** Doubly Linked Lis operations definition end ***/

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compar(const void *a, const void *b) {
	return (*(int *) a - *(int *) b);
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

int threeSumClosest(int* nums, int numsSize, int target) {
	if (nums == NULL || numsSize < 3) {
		return NULL;
	}

	// copy nums to a
	int *a = (int *) calloc(numsSize, sizeof(int));
	int i = 0;
	for (i = 0; i < numsSize; i++) {
		a[i] = nums[i];
	}

	// sort the array first
	qsort((void *) a, numsSize, sizeof(int), compar);

	int minDiff = INT_MAX;
	int result = 0;

	i = 0;
	while (i < numsSize - 2) {
		int begin = i + 1;
		int end = numsSize - 1;

		while (begin < end) {
			int sum = a[begin] + a[end] + a[i];
			int diff = sum - target;

			// get the absolute value of diff and use it to compare to minDiff
			int absDiff = (diff < 0) ? -diff : diff;
			if (minDiff > absDiff) {
				minDiff = absDiff;
				result = sum;
			}

			// if diff > 0, then move end index backward to make the sum smaller
			// else if diff < 0, move begin index forward to make the sum larger
			// else, that is diff = 0, the result is perfect and return it!
			if (diff > 0) {
				while (begin < end && a[end] == a[end - 1]) {
					end--;
				}
				end--;
			} else if (diff < 0) {
				while (begin < end && a[begin] == a[begin + 1]) {
					begin++;
				}
				begin++;
			} else {
				return result;
			}
		}

		i++;
	}

	// free memory
	free(a);

	return result;
}
