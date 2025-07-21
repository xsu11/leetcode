package com.xinsu.util;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class BinaryTree {

    public List<Integer> bfs(final TreeNode root) {
        // boundary case
        if (root == null) {
            return Collections.emptyList();
        }

        final List<Integer> result = new ArrayList<>();

        final Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            final TreeNode node = queue.poll();
            result.add(node.val);

            if (node.left != null) {
                queue.offer(node.left);
            }

            if (node.right != null) {
                queue.offer(node.right);
            }
        }

        return result;
    }

    public void dfsInOrder(final TreeNode root, final List<Integer> nodes) {
        // bottom-up condition
        if (root == null) {
            return;
        }

        // in-order traverse
        dfsInOrder(root.left, nodes);
        nodes.add(root.val);
        dfsInOrder(root.right, nodes);
    }

    public List<Integer> inOrderTraversal(final TreeNode root) {
        // boundary case
        if (root == null) {
            return Collections.emptyList();
        }

        final List<Integer> result = new ArrayList<>();

        final Deque<TreeNode> stack = new LinkedList<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            // cur goes to the left most node
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            // 1. cur is the null left child of the left most node, which means this node's left child has been traversed

            // 2. cur goes back to its root, that is the left most node, then traverse cur, that is the root
            cur = stack.pop();
            result.add(cur.val);

            // 3. cur goes to the right child to traverse right subtree
            cur = cur.right;
        }

        return result;
    }

    public void dfsPreOrder(final TreeNode root, final List<Integer> nodes) {
        // bottom-up condition
        if (root == null) {
            return;
        }

        // pre-order traverse
        nodes.add(root.val);
        dfsPreOrder(root.left, nodes);
        dfsPreOrder(root.right, nodes);
    }

    public List<Integer> preorderTraversal(final TreeNode root) {
        // boundary case
        if (root == null) {
            return Collections.emptyList();
        }

        final List<Integer> result = new ArrayList<>();

        final Deque<TreeNode> stack = new LinkedList<>();
        TreeNode cur = root;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                // 1. traverse cur, that is the root
                result.add(cur.val);

                stack.push(cur);

                // 2. cur goes to left child to traverse left subtree
                cur = cur.left;
            }
            // cur is the null left child of the left most node, which means this node's left child has been traversed

            // 3. cur goes to the right child to traverse right subtree
            cur = stack.pop();
            cur = cur.right;
        }

        return result;
    }

    public void dfsPostOrder(final TreeNode root, final List<Integer> nodes) {
        // bottom-up condition
        if (root == null) {
            return;
        }

        // pre-order traverse
        dfsPostOrder(root.left, nodes);
        dfsPostOrder(root.right, nodes);
        nodes.add(root.val);
    }

    public List<Integer> postorderTraversal(final TreeNode root) {
        // boundary case
        if (root == null) {
            return Collections.emptyList();
        }

        final List<Integer> result = new ArrayList<>();

        final Deque<TreeNode> stack = new LinkedList<>();
        TreeNode cur = root;
        TreeNode prev = null; // points to last traversed node
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            // 1. cur is the null left child of the left most node, which means this node's left child has been traversed

            cur = stack.peek();
            if (cur.right != null && cur.right != prev) {
                // 2. cur goes to the right child to traverse right subtree
                cur = cur.right;
            } else { // cur.right == null || cur.right == prev
                // 3. right subtree has been traversed, cur goes back to the root, then traverse cur, that is the root
                cur = stack.pop();
                result.add(cur.val);

                // update prev to last traversed node, that is cur
                prev = cur;

                // null cur to indicate this tree has been traversed completely
                cur = null;
            }
        }

        return result;
    }

}
