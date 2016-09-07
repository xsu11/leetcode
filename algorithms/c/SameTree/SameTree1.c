/*
 * SameTree1.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 *
 * This is recursion solution. Use in-order tree traversal.
 */

/*
 Given two binary trees, write a function to check if they are equal or not.

 Two binary trees are considered equal if they are structurally identical and
 the nodes have the same value.
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

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	// base case
	if (p == NULL || q == NULL) {
		return (bool) (p == q);
	} else if (p->val != q->val) {
		return false;
	}

	// recursion
	return (bool) (isSameTree(p->left, q->left)
			&& isSameTree(p->right, q->right));
}
