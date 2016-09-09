/*
 * BalancedBinaryTree.c
 *
 *  Created on: Sep 09, 2016
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

bool isBalanced(struct TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	int lDepth = maxDepth(root->left);
	int rDepth = maxDepth(root->right);

	if (lDepth - rDepth < -1 || lDepth - rDepth > 1) {
		return false;
	}

	return isBalanced(root->left) && isBalanced(root->right);
}
