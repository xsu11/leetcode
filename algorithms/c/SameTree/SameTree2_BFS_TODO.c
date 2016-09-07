/*
 * SameTree2.c
 *
 *  Created on: Sep 06, 2016
 *      Author: xinsu
 *
 * This is Breadth First Search (BFS) solution. Use queue.
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

// TODO - Add Queue structure and operations definitions.

// Add this struct difinition to scilent the show or error.
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	// TODO - BFS

	return true;
}
