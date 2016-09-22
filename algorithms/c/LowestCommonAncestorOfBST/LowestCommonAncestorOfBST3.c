/*
 * LowestCommonAncestorOfBST2.c
 *
 *  Created on: Sep 22, 2016
 *      Author: xinsu
 *
 * Assume all values in the tree are identical, and p and q are in the tree.
 *
 * Recursion
 */

/*
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 *
 * According to the definition of LCA on Wikipedia:
 * “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that
 * has both v and w as descendants (where we allow a node to be a descendant of itself).”
 *
 *         _______6______
 *        /              \
 *     ___2__          ___8__
 *    /      \        /      \
 *    0       4       7       9
 *          /  \
 *          3   5
 *
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
 * Another example is LCA of nodes 2 and 4 is 2,
 * since a node can be a descendant of itself according to the LCA definition.
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

// Add this structure definition to silence the show of error.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p,
		struct TreeNode* q) {
	if (root == NULL || p == NULL || q == NULL) {
		return NULL;
	} else if (((long) root->val - p->val) * ((long) root->val - q->val) < 1) {
		return root;
	}

	root = (root->val > p->val) ? root->left : root->right;
	return lowestCommonAncestor(root, p, q);
}
