package com.xinsu;

import com.xinsu.util.ListNode;

/**
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

public class Q19_RemoveNthNodeFromEndOfList {

    public ListNode removeNthFromEnd(ListNode head, int n) {
        // boundary case
        if (head == null) {
            return null;
        }

        final ListNode dummy = new ListNode(0, head);

        ListNode prev = dummy;
        ListNode slow = head;
        ListNode fast = head;

        /*
         * prev         head/slow/fast
         * dummy   ->   1   ->   2   ->   3   ->   4   ->   5   ->   6   ->   null
         */

        // move fast n steps
        for (int i = 0; i < n; i++) {
            if (fast == null) {
                throw new IllegalArgumentException("n exceeds list length. n=" + n);
            }

            fast = fast.next;
        }

        /*
         * n = 3
         * prev         head/slow                  fast
         * dummy   ->   1   ->   2   ->   3   ->   4   ->   5   ->   6   ->   null
         */
        /*
         * n = 6
         * prev         head/slow                                             fast
         * dummy   ->   1   ->   2   ->   3   ->   4   ->   5   ->   6   ->   null, n == list length, remove head;
         */

        // move slow/fast together to the end of the list
        while (fast != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next;
        }

        /*
         * n = 3
         *              head              prev     slow                       fast
         * dummy   ->   1   ->   2   ->   3   ->   4   ->   5   ->   6   ->   null
         */
        /*
         * n = 6
         * prev         head/slow                                             fast
         * dummy   ->   1   ->   2   ->   3   ->   4   ->   5   ->   6   ->   null, n == list length, remove head;
         */

        // remove slow
        prev.next = slow.next;

        /*
         * n = 3
         *              head              prev                       fast
         * dummy   ->   1   ->   2   ->   3   ->   5   ->   6   ->   null
         */
        /*
         * n = 6
         * prev                                                      fast
         * dummy   ->   2   ->   3   ->   4   ->   5   ->   6   ->   null, n == list length, remove head;
         */

        return dummy.next;
    }

}
