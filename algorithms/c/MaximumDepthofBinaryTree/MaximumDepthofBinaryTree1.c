/*
 * MaximumDepthofBinaryTree1.c
 *
 *  Created on: Sep 09, 2016
 *      Author: xinsu
 */

/*
 Given a binary tree, find its maximum depth.

 The maximum depth is the number of nodes along the longest path
 from the root node down to the farthest leaf node.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdbool.h>

// Add this struct difinition to silence the show or error.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*** Queue structure definition ***/
struct QueueNode {
	int info;
	struct TreeNode *data;
	struct QueueNode *next;
};

struct QueueTreeNode {
	int size;
	struct QueueNode *front;
	struct QueueNode *back;
};
/*** Queue structure definition end ***/

/*** Queue operations definition ***/
struct QueueTreeNode *create() {
	struct QueueTreeNode *queue = (struct QueueTreeNode *) calloc(1,
			sizeof(struct QueueTreeNode));
	return queue;
}

void destroy(struct QueueTreeNode *queue) {
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

struct QueueNode *head(struct QueueTreeNode *queue) {
	if (queue == NULL || queue->size == 0) {
		return NULL;
	}

	return queue->front;
}

bool inqueue(struct QueueTreeNode *queue, struct TreeNode *data, int info) {
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

struct TreeNode *dequeue(struct QueueTreeNode *queue, int *info) {
	if (queue == NULL || queue->size == 0) {
		return NULL;
	}

	struct QueueNode *node = queue->front;
	struct TreeNode *data = node->data;
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

int maxDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	struct QueueTreeNode *queue = create();
	struct TreeNode *curNode = NULL;
	int depth = 0;
	inqueue(queue, root, depth);
	while ((curNode = dequeue(queue, &depth)) != NULL) {
		if (curNode->left != NULL) {
			inqueue(queue, curNode->left, depth + 1);
		}
		if (curNode->right != NULL) {
			inqueue(queue, curNode->right, depth + 1);
		}
	}

	destroy(queue);
	return depth + 1;
}
