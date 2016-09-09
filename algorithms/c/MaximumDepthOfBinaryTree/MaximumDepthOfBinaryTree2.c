/*
 * MaximumDepthofBinaryTree2.c
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

int maxTreeDepth(struct TreeNode* root, int depth) {
	if (root == NULL) {
		return depth;
	}

	int lDepth = maxTreeDepth(root->left, depth + 1);
	int rDepth = maxTreeDepth(root->right, depth + 1);

	return (lDepth > rDepth) ? lDepth : rDepth;
}

int maxDepth(struct TreeNode* root) {
	return maxTreeDepth(root, 0);
}
