/*
 * MinimumDepthOfBinaryTree2.c
 *
 *  Created on: Sep 09, 2016
 *      Author: xinsu
 *
 * Recursion
 */

/*
 Given a binary tree, find its minimum depth.

 The minimum depth is the number of nodes along the shortest path
 from the root node down to the nearest leaf node.
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

int minDepth(struct TreeNode* root) {
	if (root == NULL) {
		return 0;
	} else if (root->left == NULL && root->right == NULL) {
		return 1;
	} else if (root->left != NULL && root->right == NULL) {
		return minDepth(root->left) + 1;
	} else if (root->left == NULL && root->right != NULL) {
		return minDepth(root->right) + 1;
	}

	int lMinDepth = 1;
	int rMinDepth = 1;
	lMinDepth += minDepth(root->left);
	rMinDepth += minDepth(root->right);

	return lMinDepth < rMinDepth ? lMinDepth : rMinDepth;
}
