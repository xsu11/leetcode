/*
 * SymmetricTree3_DFS_like_BFS.c
 *
 *  Created on: Sep 08, 2016
 *      Author: xinsu
 *
 * DFS. This solution is actually the same like BFS, but use Stack instead.
 * Use "whether the StackNode is in the Stack or not" to record if it is accessed.
 * If a StackNode is not accessed at all, it is in the Stack;
 * if a StackNode is being accessed right now, it is popped from the Stack (not in the Stack),
 * but this access process is atomic;
 * if a StackNode is been accessed, it is popped from the Stack (not in the Stack).
 * Therefore: before accessing (in Stack) -> accessing (out of Stack) -> after accessing (out of Stack).
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

/*** Stack structure definition ***/
struct StackNode {
	int info;
	struct TreeNode *data;
	struct StackNode *next;
};

struct StackTreeNode {
	int size;
	struct StackNode *head;
};
/*** Stack structure definition end ***/

/*** Stack operations definition ***/
struct StackTreeNode *create() {
	struct StackTreeNode *stack = (struct StackTreeNode *) calloc(1,
			sizeof(struct StackTreeNode));
	return stack;
}

void destroy(struct StackTreeNode *stack) {
	if (stack != NULL) {
		if (stack->head != NULL) {
			struct StackNode *curNode = stack->head;
			while (stack->head != NULL) {
				stack->head = stack->head->next;
				free(curNode);
				curNode = stack->head;
			}
		}
		free(stack);
	}
}

struct StackNode *peak(struct StackTreeNode *stack) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	return stack->head;
}

bool push(struct StackTreeNode *stack, struct TreeNode *data, int info) {
	if (stack == NULL) {
		return false;
	}

	// alloc memory for new node
	struct StackNode *node = (struct StackNode *) calloc(1,
			sizeof(struct StackNode));
	node->data = data;
	node->info = info;
	node->next = stack->head;
	stack->head = node;
	stack->size++;

	return true;
}

struct TreeNode *pop(struct StackTreeNode *stack, int *info) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	struct StackNode *node = stack->head;
	struct TreeNode *data = node->data;
	if (info != NULL) {
		*info = node->info;
	}
	stack->head = stack->head->next;
	stack->size--;
	free(node);
	return data;
}
/*** Stack operations definition end ***/

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	bool result = true;

	// create two stacks for both subtrees and push two children of root
	struct StackTreeNode *lStack = create();
	struct StackTreeNode *rStack = create();
	push(lStack, root->left, 0);
	push(rStack, root->right, 0);

	while (result == true && lStack->size != 0 && rStack->size != 0) {
		struct TreeNode *lNode = pop(lStack, NULL);
		struct TreeNode *rNode = pop(rStack, NULL);

		if (lNode == NULL && rNode == NULL) {
			continue;
		} else if (lNode == NULL ^ rNode == NULL) {
			result = false;
		} else if (lNode->val != rNode->val) {
			result = false;
		} else {
			push(lStack, lNode->left, 0);
			push(rStack, rNode->right, 0);

			push(lStack, lNode->right, 0);
			push(rStack, rNode->left, 0);
		}
	}

	destroy(lStack);
	destroy(rStack);
	return result;
}
