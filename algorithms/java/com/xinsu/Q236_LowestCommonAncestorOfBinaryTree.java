package com.xinsu;

import com.xinsu.util.TreeNode;

/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as
 * the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * Example 2:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA
 * definition.
 * Example 3:
 *
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [2, 105].
 * -109 <= Node.val <= 109
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
 */

public class Q236_LowestCommonAncestorOfBinaryTree {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // bottom-up condition
        // for null node, just return null to indicate that no p/q are found in the tree of root
        if (root == null) {
            return null;
        }

        // From Constraints: tree has more than 2 nodes.
        // From Constraints: p and q will exist in the tree.
        /*
         * Three cases:
         * 1. root has no children: root is leaf and must be p/q. This happens ONLY when the other is root's sibling
         * 2. root has one child: either root is p/q, or p/q are in its child's subtree
         * 3. root has two children: either root is p/q, or p/q are in its children's subtree
         * For case 2 and 3: if root is p/q, the other one must be in subtree, otherwise, go to each subtree
         */
        if (root == p || root == q) {
            return root;
        }

        final TreeNode left = lowestCommonAncestor(root.left, p, q);
        final TreeNode right = lowestCommonAncestor(root.right, p, q);

        // Either p/q are in the same subtree of root: left/right has only one non-null returned
        // or p/q are in different subtrees of root: left and right are both non-null returned

        // if p and q are in different subtrees, common ancestor can only be the root of these two subtrees
        if (left != null && right != null) {
            // common ancestor can only be root when left and right returns not-null value
            return root;
        }

        // otherwise, either q is in p's subtree or p is in q's subtree
        return left != null ? left : right;
    }

}
