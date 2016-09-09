/*
 * BinaryTreeLevelOrderTraversal.c
 *
 *  Created on: Sep 08, 2016
 *      Author: xinsu
 */

/*
 Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).

 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
   15  7
 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
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

int **levelOrder(struct TreeNode *root, int **columnSizes, int *returnSize) {
	if (root == NULL) {
		*columnSizes = NULL;
		returnSize = NULL;
		return NULL;
	}

	// First use BFSQueue do BFS, but put all the dequeued elements into queue2.
	struct QueueTreeNode *BFSQueue = create();
	struct QueueTreeNode *additionalQueue = create();
	struct TreeNode *curTreeNode = NULL;
	int level = 0;
	inqueue(BFSQueue, root, level);

	while ((curTreeNode = dequeue(BFSQueue, &level)) != NULL) {
		inqueue(additionalQueue, curTreeNode, level); // put all elements into queue2
		if (curTreeNode->left != NULL) {
			inqueue(BFSQueue, curTreeNode->left, level + 1);
		}
		if (curTreeNode->right != NULL) {
			inqueue(BFSQueue, curTreeNode->right, level + 1);
		}
	}

	*returnSize = level + 1;

	// alloc memory for columnSizes based on returnSize
	*columnSizes = (int *) calloc(*returnSize, sizeof(int));

	// Then traverse the queue2 and store the columnSizes
	struct QueueNode *curQueueNode = additionalQueue->front;
	while (curQueueNode != NULL) {
		columnSizes[0][curQueueNode->info]++;
		curQueueNode = curQueueNode->next;
	}

	// Then use columnSizes to alloc memory for result,
	// but after allocation for each column, clear column size
	int **result = (int **) calloc(*returnSize, sizeof(int *));
	int i = 0;
	for (i = 0; i < *returnSize; i++) {
		result[i] = (int *) calloc(columnSizes[0][i], sizeof(int));
		columnSizes[0][i] = 0;
	}

	// Traverse queue2 again and set result
	curQueueNode = additionalQueue->front;
	while (curQueueNode != NULL) {
		result[curQueueNode->info][columnSizes[0][curQueueNode->info]] =
				curQueueNode->data->val;
		columnSizes[0][curQueueNode->info]++;
		curQueueNode = curQueueNode->next;
	}

	destroy(BFSQueue);
	destroy(additionalQueue);
	return result;
}
