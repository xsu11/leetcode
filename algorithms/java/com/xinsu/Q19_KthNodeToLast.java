package com.xinsu;

import com.xinsu.util.ListNode;

/*
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * Example 2:
 *
 * Input: head = [1], n = 1
 * Output: []
 * Example 3:
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 * Follow up: Could you do this in one pass?
 */

public class Q19_KthNodeToLast {

    public int kthToLast(ListNode head, int k) {
        // boundary case
        if (head == null || k <= 0) {
            return -1;
        }

        ListNode slow = head;
        ListNode fast = head;

        // move fast k steps ahead
        for (int i = 0; i < k; i++) {
            if (fast == null) {
                return -1;
            }

            fast = fast.next;
        }

        // then move slow and fast together to the end of list
        while (fast != null) {
            slow = slow.next;
            fast = fast.next;
        }

        return slow.val;
    }

}
