/*
 * BinaryTreePaths.c
 *
 *  Created on: Sep 24, 2016
 *      Author: xinsu
 *
 * Use DFS to traverse the tree.
 * It is easy to use dynamic data structure, like List in Java or vector in C++.
 * It is also easy to use recurssion if there is dynamic data structure.
 */

/*
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *    1
 *  /   \
 * 2     3
 *  \
 *  5
 *
 * All root-to-leaf paths are:
 * ["1->2->5", "1->3"]
 *
 * Credits:
 * Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
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

// Add this structure definition to silence the show of error
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/*** Stack structure definition ***/
struct StackNode {
	int info;
	void *data;
	struct StackNode *next;
};

struct Stack {
	int size;
	struct StackNode *head;
};
/*** Stack structure definition end ***/

/*** Stack operations definition ***/
struct Stack *create() {
	struct Stack *stack = (struct Stack *) calloc(1, sizeof(struct Stack));
	return stack;
}

void destroy(struct Stack *stack) {
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

struct StackNode *peak(struct Stack *stack) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	return stack->head;
}

bool push(struct Stack *stack, void *data, int info) {
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

void *pop(struct Stack *stack, int *info) {
	if (stack == NULL || stack->size == 0) {
		return NULL;
	}

	struct StackNode *node = stack->head;
	void *data = node->data;
	if (info != NULL) {
		*info = node->info;
	}

	stack->head = stack->head->next;
	stack->size--;
	free(node);

	return data;
}
/*** Stack operations definition end ***/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define LEAVE -1
#define ZERO_CHILD 0
#define ONE_CHILD 1
#define TWO_CHILDREN 2

int countChildren(struct TreeNode *node) {
	int count = LEAVE;
	if ((node->left != NULL) ^ (node->right != NULL)) {
		count = ONE_CHILD;
	} else if (node->left != NULL && node->right != NULL) {
		count = TWO_CHILDREN;
	}

	return count;
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
	if (root == NULL) {
		return NULL;
	}

	struct Stack *resultStack = create(); // store the result strings
	struct Stack *stack = create(); // use for DFS
	struct StackNode *stackNode = NULL; // peak node in stack
	int i = 0;

	push(stack, (void *) root, countChildren(root));

	while ((stackNode = peak(stack)) != NULL) {
		struct TreeNode *curNode = (struct TreeNode *) stackNode->data; // tree node stored in the stack node

		// info = LEAVE leave node
		// info = ZERO_CHILD: all children have been traversed
		// info = ONE_CHILD: one child has not been traversed
		// info = TWO_CHILDREN: two children have not been traversed
		if (stackNode->info == LEAVE) {
			// traverse the stack from top to bottom to store the path

			// first calculate the total length
			struct StackNode *curStackNode = stack->head; // current node in stack
			int length = 0; // result string's length
			while (curStackNode != NULL) {
				int v = ((struct TreeNode *) curStackNode->data)->val; // value in tree node

				if (v == 0) {
					length++;
				} else {
					if (v < 0) {
						length++;
						v *= -1;
					}

					while (v != 0) {
						length++;
						v /= 10;
					}
				}

				curStackNode = curStackNode->next;

				if (curStackNode != NULL) {
					length += 2; // ->
				}
			}

			// user the length to alloc memory
			char *s = (char *) calloc(length + 1, sizeof(char));

			// traverse the stack to store the string
			curStackNode = stack->head;
			i = length - 1;
			while (curStackNode != NULL) {
				bool negFlag = false;
				int v = ((struct TreeNode *) curStackNode->data)->val;

				if (v == 0) {
					s[i--] = '0';
				} else {
					if (v < 0) {
						negFlag = true;
						v *= -1;
					}

					while (v != 0) {
						s[i--] = v % 10 + '0';
						v /= 10;
					}

					if (negFlag == true) {
						s[i--] = '-';
					}
				}

				curStackNode = curStackNode->next;

				if (curStackNode != NULL) {
					s[i--] = '>';
					s[i--] = '-';
				}
			}

			push(resultStack, (void *) s, NULL);
			pop(stack, NULL);
		} else if (stackNode->info == ZERO_CHILD) {
			pop(stack, NULL);
		} else if (stackNode->info == 1) {
			if (curNode->left != NULL && curNode->right != NULL) {
				push(stack, curNode->right, countChildren(curNode->right));
			} else if (curNode->left != NULL) {
				push(stack, curNode->left, countChildren(curNode->left));
			} else if (curNode->right != NULL) {
				push(stack, curNode->right, countChildren(curNode->right));
			}

			stackNode->info = ZERO_CHILD;
		} else if (stackNode->info == TWO_CHILDREN) {
			push(stack, curNode->left, countChildren(curNode->left));
			stackNode->info = ONE_CHILD;
		}
	}

	*returnSize = resultStack->size;
	char **result = (char **) calloc(*returnSize, sizeof(char *));

	struct StackNode *curStackNode = resultStack->head; // current node in resultStack
	for (i = *returnSize - 1; i > -1; i--, curStackNode = curStackNode->next) {
		result[i] = (char *) curStackNode->data;
	}

	destroy(resultStack);
	destroy(stack);
	return result;
}
