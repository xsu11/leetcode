/*
 * MaximumDepthofBinaryTree3.c
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

// Add this struct difinition to silence the show or error.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

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
