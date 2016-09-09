/*
 * PathSum2.c
 *
 *  Created on: Sep 09, 2016
 *      Author: xinsu
 *
 * Recursion
 */

/*
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that
 adding up all the values along the path equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \      \
 7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

bool hasPathSum(struct TreeNode* root, int sum) {
	if (root == NULL) {
		return false;
	} else if (root->left == NULL && root->right == NULL) {
		return root->val == sum;
	}

	bool lResult = false;
	bool rResult = false;

	if (root->left != NULL) {
		lResult = hasPathSum(root->left, sum - root->val);
	}
	if (root->right != NULL) {
		rResult = hasPathSum(root->right, sum - root->val);
	}
	return lResult || rResult;
}
