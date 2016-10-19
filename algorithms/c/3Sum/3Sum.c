/*
 * 3Sum.c
 *
 *  Created on: Oct 04, 2016
 *      Author: xinsu
 */

/*
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 Find all unique triplets in the array which gives the sum of zero.

 Note: The solution set must not contain duplicate triplets.

 For example, given array S = [-1, 0, 1, 2, -1, -4],

 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 */

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
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

/*
 * void qsort(void *base,									// array
 * 			  size_t nel,									// number of elements in the array
 * 			  size_t width,									// width of element in the array
 *			  int (*compar)(const void *, const void *));	// comparison function
 */

int **threeSum(int *nums, int numsSize, int *returnSize) {
	if (nums == NULL || numsSize < 3) {
		*returnSize = 0;
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

	struct Dll *dll = create();

	i = 0;
	while (a[i] <= 0 && i < numsSize - 2) {
		int target = 0 - a[i];
		int begin = i + 1;
		int end = numsSize - 1;

		while (begin < end) {
			if (a[begin] + a[end] == target) {
				// alloc memory for this result array of 3 ints and set values
				int *r = (int *) calloc(3, sizeof(int));
				r[0] = a[i];
				r[1] = a[begin];
				r[2] = a[end];

				// check if this result is in the dll
				// if it is already existed, free it
				// else, add it to dll
				if (exists(dll, (void *) r, 3, dllCompar)) {
					free(r);
				} else {
					add(dll, dll->size, (void *) r, NULL);
				}

				while (begin < end && a[begin] == a[begin + 1]) {
					begin++;
				}
				begin++;
			} else if (a[begin] + a[end] > target) {
				end--;
			} else {
				begin++;
			}
		}

		i++;
	}

	// alloc memory for results to store all the result arrays
	int **results = (int **) calloc(dll->size, sizeof(int *));

	i = 0;
	struct DllNode *curNode = dll->head;
	while (curNode != NULL) {
		results[i++] = (int *) curNode->data;
		curNode = curNode->next;
	}
	*returnSize = dll->size;

	// free memory
	free(a);
	destroy(dll);

	return results;
}
