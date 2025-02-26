package com.xinsu;

import com.xinsu.util.TreeNode;

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
