/*
 * InvertBinaryTree.c
 *
 *  Created on: Sep 20, 2016
 *      Author: xinsu
 *
 * Recursive solution.
 * Another solution is to use a queue to implement BFS.
 */

/*
 * Invert a binary tree.
 *
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 *
 * to
 *
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 *
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * Google: 90% of our engineers use the software you wrote (Homebrew),
 * but you can’t invert a binary tree on a whiteboard so fuck off.
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

// Add this structure definition to silence the show of error
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode *invertTree(struct TreeNode *root) {
	if (root == NULL) {
		return NULL;
	}

	struct TreeNode *l = invertTree(root->left);
	root->left = invertTree(root->right);
	root->right = l;

	return root;
}
