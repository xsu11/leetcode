package com.xinsu;

import com.xinsu.util.TreeNode;

public class Q236_LowestCommonAncestorOfBinaryTree {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // bottom-up condition
        if (root == null) {
            return null;
        }

        if (root == p || root == q) {
            return root;
        }

        final TreeNode left = lowestCommonAncestor(root.left, p, q);
        final TreeNode right = lowestCommonAncestor(root.right, p, q);

        // if p and q are in different subtrees, common ancestor can only be the root of these two subtrees
        if (left != null && right != null) {
            // common ancestor can only be root when left and right returns not-null value
            return root;
        }

        // otherwise, either q is in p's subtree or p is in q's subtree
        return left != null ? left : right;
    }

}
