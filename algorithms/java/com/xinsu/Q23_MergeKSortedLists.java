package com.xinsu;

import com.xinsu.util.ListNode;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 * 提示：
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 */

public class Q23_MergeKSortedLists {

    public ListNode mergeKLists(ListNode[] lists) {
        final PriorityQueue<ListNode> queue = createSmallestNodeQueue(lists);
        return merge(queue);
    }

    private static PriorityQueue<ListNode> createSmallestNodeQueue(ListNode[] lists) {
        // create a queue to put the smallest node (head) of every list in
        final PriorityQueue<ListNode> queue = new PriorityQueue<>(Comparator.comparingInt(a -> a.val));
        for (final ListNode head : lists) {
            if (head != null) {
                queue.offer(head);
            }
        }
        return queue;
    }

    private static ListNode merge(PriorityQueue<ListNode> queue) {
        final ListNode dummy = new ListNode();
        ListNode current = dummy;

        while (!queue.isEmpty()) {
            final ListNode smallestNode = queue.poll();
            current.next = smallestNode;

            // put node next to smallestNode in that list into the queue
            if (smallestNode.next != null) {
                queue.offer(smallestNode.next);
            }

            // move forward
            current = current.next;
        }

        return dummy.next;
    }

}
