package com.xinsu;

import com.xinsu.util.TreeNode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

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

        // root level: 0 in natural order
        final List<Integer> currentLevel = result.get(level);
        if (level % 2 == 0) {
            // in natural order, add root to the end
            currentLevel.add(root.val);
        } else {
            // in reverse order, add root to the beginning
            currentLevel.add(0, root.val);
        }

        traverse(root.left, result, level + 1);
        traverse(root.right, result, level + 1);
    }

}
