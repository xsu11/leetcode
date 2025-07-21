package com.xinsu;

import com.xinsu.util.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/*
 * Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to
 * right, then right to left for the next level and alternate between).
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 * Example 2:
 *
 * Input: root = [1]
 * Output: [[1]]
 * Example 3:
 *
 * Input: root = []
 * Output: []
 *
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 */

public class Q103_BinaryTreeZigzagLevelOrderTraversal {

    public List<List<Integer>> zigzagLevelOrder(final TreeNode root) {
        final List<List<Integer>> result = new ArrayList<>();
        traverse(root, result, 0);
        return result;
    }

    private void traverse(final TreeNode root, final List<List<Integer>> result, final int level) {
        // bottom-up condition
        if (root == null) {
            return;
        }

        // init list in result if necessary
        if (result.size() <= level) {
            result.add(new LinkedList<>());
        }

        // add root to current level
        final List<Integer> currentLevel = result.get(level);

        if (level % 2 == 0) {
            // even level in natural order, add root to the end
            currentLevel.add(root.val);
        } else {
            // odd level in reverse order, add root to the beginning
            currentLevel.add(0, root.val);
        }

        traverse(root.left, result, level + 1);
        traverse(root.right, result, level + 1);
    }

}
