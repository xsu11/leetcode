///*
// * SymmetricTree1.c
// *
// *  Created on: Sep 07, 2016
// *      Author: xinsu
// *
// * This is recursion solution.
// */
//
///*
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
// 1
// / \
// 2   2
// / \ / \
// 3  4 4  3
//
// But the following [1,2,2,null,3,null,3] is not:
//
// 1
// / \
// 2   2
// \   \
//   3    3
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
// */
//
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//
//#include <stdio.h>
//#include <stdbool.h>
//
//// Add this struct difinition to scilent the show or error.
//struct TreeNode {
//	int val;
//	struct TreeNode *left;
//	struct TreeNode *right;
//};
//
//bool isSymmetricTree(struct TreeNode* node1, struct TreeNode* node2) {
//	// base case
//	if (node1 == NULL || node2 == NULL) {
//		return (bool) (node1 == node2);
//	} else if (node1->val != node2->val) {
//		return false;
//	}
//
//	// do recursion
//	return (bool) (isSymmetricTree(node1->right, node2->left) && isSymmetricTree(node1->left, node2->right));
//}
//
//bool isSymmetric(struct TreeNode* root) {
//	// special input
//	if (root == NULL) {
//		return true;
//	}
//
//	return (bool) isSymmetricTree(root->left, root->right);
//}
