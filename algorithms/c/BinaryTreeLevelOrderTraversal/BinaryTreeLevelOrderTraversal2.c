/*
 * BinaryTreeLevelOrderTraversal2.c
 *
 *  Created on: Sep 08, 2016
 *      Author: xinsu
 *
 * Recursion
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
   15   7
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

// From 104. Maximum Depth of Binary Tree
int maxDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	int lDepth = 1;
	int rDepth = 1;
	lDepth += maxDepth(root->left);
	rDepth += maxDepth(root->right);

	return (lDepth > rDepth) ? lDepth : rDepth;
}

int levelNodeCount(struct TreeNode *root, int level, int curLevel) {
	if (root == NULL) {
		return 0;
	} else if (curLevel == level) {
		return 1;
	}

	return levelNodeCount(root->left, level, curLevel + 1)
			+ levelNodeCount(root->right, level, curLevel + 1);

}

void levelTraversal(struct TreeNode *root, int level, int curLevel, int *result,
		int *resultSize) {
	if (root == NULL) {
		return;
	} else if (curLevel == level) {
		result[*resultSize] = root->val;
		(*resultSize)++;
		return;
	}

	levelTraversal(root->left, level, curLevel + 1, result, resultSize);
	levelTraversal(root->right, level, curLevel + 1, result, resultSize);
}

int **levelOrder(struct TreeNode *root, int **columnSizes, int *returnSize) {
	if (root == NULL) {
		*columnSizes = NULL;
		returnSize = NULL;
		return NULL;
	}

	// get depth of the tree and use it to alloc memory
	*returnSize = maxDepth(root);
	*columnSizes = (int *) calloc(*returnSize, sizeof(int));
	int **result = (int **) calloc(*returnSize, sizeof(int *));

	int i = 0;
	for (i = 0; i < *returnSize; i++) {
		// call levelNodeCount to get the count of Nodes in level i and store it in columnSize[0][i]
		columnSizes[0][i] = levelNodeCount(root, i, 0);

		// alloc memory for result[i] using count of nodes in level i
		result[i] = (int *) calloc(columnSizes[0][i], sizeof(int));

		// call levelTraversal to traverse all nodes in level i and store into result[i]
		int resultSize = 0;
		levelTraversal(root, i, 0, result[i], &resultSize);
	}

	return result;
}
