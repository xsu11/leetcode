/*
 * Queue.c
 *
 *  Created on: Sep 17, 2016
 *      Author: xinsu
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*** Queue structure definition ***/
struct QueueNode {
	int info;
	void *data;
	struct QueueNode *next;
};

struct Queue {
	int size;
	struct QueueNode *front;
	struct QueueNode *back;
};
/*** Queue structure definition end ***/

/*** Queue operations definition ***/
struct Queue *create() {
	struct Queue *queue = (struct Queue *) calloc(1, sizeof(struct Queue));
	// automatically...
	// queue->size = 0;
	// queue->front = NULL;
	// queue->back = NULL;
	return queue;
}

void destroy(struct Queue *queue) {
	if (queue != NULL) {
		if (queue->front != NULL) {
			struct QueueNode *curNode = queue->front;
			while (queue->front != NULL) {
				queue->front = queue->front->next;
				free(curNode);
				curNode = queue->front;
			}
		}
		free(queue);
	}
}

struct QueueNode *head(struct Queue *queue) {
	if (queue == NULL || queue->size == 0) {
		return NULL;
	}

	return queue->front;
}

bool inqueue(struct Queue *queue, void *data, int info) {
	if (queue == NULL) {
		return false;
	}

	// alloc memory for new node
	struct QueueNode *node = (struct QueueNode *) calloc(1,
			sizeof(struct QueueNode));

	node->data = data;
	node->info = info;

	if (queue->size == 0) {
		queue->front = node;
	} else {
		queue->back->next = node;
	}
	queue->back = node;
	queue->size++;

	return true;
}

void *dequeue(struct Queue *queue, int *info) {
	if (queue == NULL || queue->size == 0) {
		return NULL;
	}

	struct QueueNode *node = queue->front;
	void *data = node->data;
	if (info != NULL) {
		*info = node->info;
	}

	if (queue->size == 1) {
		queue->front = NULL;
		queue->back = NULL;
	} else {
		queue->front = queue->front->next;
	}

	queue->size--;
	free(node);

	return data;
}
/*** Queue operations definition end ***/
