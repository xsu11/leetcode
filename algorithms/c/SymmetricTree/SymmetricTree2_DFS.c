/*
 * SymmetricTree2_DFS.c
 *
 *  Created on: Sep 07, 2016
 *      Author: xinsu
 *
 * DFS. Use addition info in the StackNode to record if this Node is accessed.
 * If a StackNode is not accessed at all, info = 0;
 * if a StackNode is being accessed right now, the info won't change, but this access process is atomic;
 * if a StackNode is been accessed, info = 1.
 * Therefore: before accessing (info = 0) -> accessing (info = 0) -> after accessing (info = 1).
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

// Add this struct difinition to silence the show or error.
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
	} else if (root->left == NULL || root->right == NULL) {
		return (bool) (root->left == root->right);
	} else if (root->left->val != root->right->val) {
		return false;
	}

	// Now the condition is root->left->val == root->right->val

	// create two stacks for both subtrees and push two children of root
	struct StackTreeNode *lStack = create();
	struct StackTreeNode *rStack = create();
	push(lStack, root->left, 0);
	push(rStack, root->right, 0);

	while (lStack->size != 0 && rStack->size != 0) {
		struct StackNode *lNode = peak(lStack);
		struct StackNode *rNode = peak(rStack);
		if (lNode->info == 1 && rNode->info == 1) {
			// Already checked these two trees and pop the trees' root.
			pop(lStack, NULL);
			pop(rStack, NULL);
		} else if (lNode->info == 0 && rNode->info == 0) {
			// Never check these two trees. Push the children into the stack.
			if ((lNode->data->val != rNode->data->val)
					|| ((lNode->data->left == NULL)
							^ (rNode->data->right == NULL))
					|| ((lNode->data->right == NULL)
							^ (rNode->data->left == NULL))) {
				// Not a symmetric tree. Destroy the stack and return false.
				destroy(lStack);
				destroy(rStack);
				return false;
			} else if (lNode->data->left == NULL && rNode->data->right == NULL
					&& lNode->data->right == NULL && rNode->data->left == NULL) {
				pop(lStack, NULL);
				pop(rStack, NULL);
			} else {
				// These two nodes has the same value, and Both has one child or two (symmetric).
				// Change the info to 1 and push the children into the stack.
				lNode->info = 1;
				rNode->info = 1;

				if (lNode->data->left != NULL && rNode->data->right != NULL) {
					push(lStack, lNode->data->left, 0);
					push(rStack, rNode->data->right, 0);
				}
				if (lNode->data->right != NULL && rNode->data->left != NULL) {
					push(lStack, lNode->data->right, 0);
					push(rStack, rNode->data->left, 0);
				}
			}
		} else {
			// For any other conditions, it is not a symmetric tree.
			// Destroy the stack and return false.
			destroy(lStack);
			destroy(rStack);
			return false;
		}
	}

	destroy(lStack);
	destroy(rStack);
	return true;
}
