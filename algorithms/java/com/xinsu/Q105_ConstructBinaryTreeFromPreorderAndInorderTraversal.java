package com.xinsu;

import com.xinsu.util.TreeNode;

/*
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder
 * is the inorder traversal of the same tree, construct and return the binary tree.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 * Example 2:
 *
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 *
 * Constraints:
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
 */

public class Q105_ConstructBinaryTreeFromPreorderAndInorderTraversal {

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length == 0 || inorder.length == 0) {
            return null;
        }

        return build(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private TreeNode build(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd) {
        // bottom-up condition
        if (preStart > preEnd || inStart > inEnd) {
            return null;
        }

        if (preEnd - preStart != inEnd - inStart) {
            throw new IllegalArgumentException("Preorder and Inorder length are not equal.");
        }

        final int preRoot = preorder[preStart];
        final TreeNode root = new TreeNode(preRoot);

        if (preStart == preEnd) {
            return root;
        }

        // preStart < preEnd and inStart < inEnd

        // find root
        final int inRootIndex = getInorderRootIndex(preRoot, inorder, inStart, inEnd); // root index in inorder
        if (inRootIndex == -1) {
            throw new IllegalArgumentException("No root found in inorder.");
        }

        final int leftPreStart = preStart + 1;
        final int leftPreEnd = preStart + inRootIndex - inStart;
        final int leftInStart = inStart;
        final int leftInEnd = inRootIndex - 1;

        final int rightPreStart = leftPreEnd + 1;
        final int rightPreEnd = preEnd;
        final int rightInStart = inRootIndex + 1;
        final int rightInEnd = inEnd;

        // recursively build left and right
        root.left = build(preorder, leftPreStart, leftPreEnd, inorder, leftInStart, leftInEnd);
        root.right = build(preorder, rightPreStart, rightPreEnd, inorder, rightInStart, rightInEnd);

        return root;
    }

    private int getInorderRootIndex(int preRoot, int[] inorder, int inStart, int inEnd) {
        for (int i = inStart; i < inEnd + 1; i++) {
            if (inorder[i] == preRoot) {
                return i;
            }
        }

        return -1;
    }

}
