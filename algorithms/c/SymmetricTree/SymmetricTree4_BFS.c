/*
 * SymmetricTree3.c
 *
 *  Created on: Sep 08, 2016
 *      Author: xinsu
 *
 * BFS.
 */

/*
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

 1
 / \
 2   2
 / \ / \
 3  44  3

 But the following [1,2,2,null,3,null,3] is not:

 1
 / \
 2   2
 \   \
  3   3

 Note:
 Bonus points if you could solve it both recursively and iteratively.
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

// Add this struct difinition to scilent the show or error.
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

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	bool result = true;

	// create two Queues for both subtrees and inqueue two children of root
	struct QueueTreeNode *lQueue = create();
	struct QueueTreeNode *rQueue = create();
	inqueue(lQueue, root->left, 0);
	inqueue(rQueue, root->right, 0);

	while (result == true && lQueue->size != 0 && rQueue->size != 0) {
		struct TreeNode *lNode = dequeue(lQueue, NULL);
		struct TreeNode *rNode = dequeue(rQueue, NULL);

		if (lNode == NULL && rNode == NULL) {
			continue;
		} else if (lNode == NULL ^ rNode == NULL) {
			result = false;
		} else if (lNode->val != rNode->val) {
			result = false;
		} else {
			inqueue(lQueue, lNode->left, 0);
			inqueue(rQueue, rNode->right, 0);

			inqueue(lQueue, lNode->right, 0);
			inqueue(rQueue, rNode->left, 0);
		}
	}

	destroy(lQueue);
	destroy(rQueue);
	return result;
}
