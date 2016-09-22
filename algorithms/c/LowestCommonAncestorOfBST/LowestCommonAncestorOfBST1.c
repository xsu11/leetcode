/*
 * LowestCommonAncestorOfBST1.c
 *
 *  Created on: Sep 22, 2016
 *      Author: xinsu
 *
 * Using a queue to store the path to find p, and then compare the path to find q with the queue.
 */

/*
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that
 * has both v and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *         _______6______
 *        /              \
 *     ___2__          ___8__
 *    /      \        /      \
 *    0       4       7       9
 *          /  \
 *          3   5
 *
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
 * Another example is LCA of nodes 2 and 4 is 2,
 * since a node can be a descendant of itself according to the LCA definition.
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
#include <stdlib.h>
#include <stdbool.h>

// Add this structure definition to silence the show of error.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

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

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p,
		struct TreeNode* q) {
	if (root == NULL || p == NULL || q == NULL) {
		return NULL;
	}

	struct Queue *queue = create();

	struct TreeNode *curNode = root;
	while (curNode != NULL) {
		// inqueue
		inqueue(queue, (void *) curNode, NULL);

		if (curNode->val == p->val) {
			break;
		} else if (curNode->val > p->val) {
			curNode = curNode->left;
		} else {
			curNode = curNode->right;
		}
	}

	if (curNode == NULL) {
		// p is not in the tree
		destroy(queue);
		return NULL;
	}

	curNode = root;
	struct TreeNode *result = NULL;
	struct TreeNode *parent = root;
	struct TreeNode *pNode = NULL;
	while (curNode != NULL && result == NULL) {
		// dequeue
		pNode = (struct TreeNode *) dequeue(queue, NULL);

		if (pNode == NULL || pNode != curNode) {
			// the queue is empty, or curNode just passed the junction,
			// then the parent is the result
			result = parent;
		} else if (pNode == curNode) {
			if (curNode->val == q->val) {
				result = curNode;
			} else {
				// record parent and move curNode to next level
				parent = curNode;
				curNode =
						(curNode->val > q->val) ?
								curNode->left : curNode->right;
			}
		}
	}

	// If q is not in the tree, then the result is NULL, just return it.

	destroy(queue);
	return result;
}
