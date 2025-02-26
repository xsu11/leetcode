package com.xinsu;

import com.xinsu.util.ListNode;

/*
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 *
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 *
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 *
 *
 * Constraints:
 *
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 *
 *
 * Follow-up: Can you solve the problem in O(1) extra memory space?
 */

public class Q25_ReverseNodesInKGroup {

    public ListNode reverseKGroup(ListNode head, int k) {
        // boundary case
        if (head == null || k <= 0) {
            return null;
        }

        // create dummy node to always point to the "head"
        final ListNode dummy = new ListNode(0, head);

        ListNode end = dummy;

        // k = 3
        // dummy/end
        // 0   ->   3   ->   2   ->   1   ->   4   ->   5   ->   6   ->   7   ->   8   ->   null

        while (end.next != null) {
            // invariant: end is pointing at the end of last goup
            // dummy                       end
            // 0   ->   (3   ->   2   ->   1)   ->   4   ->   5   ->   6   ->   7   ->   8   ->   null

            // use two pointers: set prev/start/end/next to proper position
            final ListNode prev = end;
            final ListNode start = prev.next;
            // move end k steps ahead to get a group
            for (int i = 0; i < k; i++) {
                if (end.next == null) {
                    // return from here when list length is not a multiple of k
                    // dummy                                                                       end
                    // 0   ->   (3   ->   2   ->   1)   ->   (6   ->   5   ->   4)   ->   7   ->   8   ->   null
                    return dummy.next;
                }
                end = end.next;
            }
            final ListNode next = end.next;

            // dummy                       prev       start             end       next
            // 0   ->   (3   ->   2   ->   1)   ->   (4   ->   5   ->   6)   ->   7   ->   8   ->   null

            // first, break group link
            end.next = null;
            // dummy                       prev       start             end       next
            // 0   ->   (3   ->   2   ->   1)   ->   (4   ->   5   ->   6)        7   ->   8   ->   null

            // then revert list [start, end]
            prev.next = reverseList(start); // reverseList() returns head of the reverted list, that is end
            // dummy                       prev       end               start     next
            // 0   ->   (3   ->   2   ->   1)   ->   (6   ->   5   ->   4)        7   ->   8   ->   null

            // finally connect group again
            start.next = next;
            // dummy                       prev       end               start     next
            // 0   ->   (3   ->   2   ->   1)   ->   (6   ->   5   ->   4)   ->   7   ->   8   ->   null

            // step forward by move end to the end of the group, which now is start
            end = start;
            // dummy                                                    end
            // 0   ->   (3   ->   2   ->   1)   ->   (4   ->   5   ->   6)   ->   7   ->   8   ->   null
        }

        // return from here only when list length is a multiple of k
        // dummy                                                                                 end
        // 0   ->   (3   ->   2   ->   1)   ->   (6   ->   5   ->   4)   ->   (7   ->   8   ->   9)   ->   null
        return dummy.next;
    }

    private ListNode reverseList(final ListNode head) {
        // boundary case
        if (head == null || head.next == null) {
            // no need to do revert
            return head;
        }

        ListNode prev = null;
        ListNode current = head;
        // prev     cur
        // null     1   ->   2   ->   3   ->   4   ->   null

        while (current != null) {
            // invariant: prev points to the head of reverted list, current points to the head of un-reverted list
            //                   prev     current
            // null     1   <-   2        3   ->   4   ->   null

            final ListNode next = current.next;
            //                   prev     current  next
            // null     1   <-   2        3   ->   4   ->   null

            current.next = prev;
            prev = current;

            //                            prev/current   next
            // null     1   <-   2   <-   3              4   ->   null

            // step forward
            current = next;
            //                            prev     current/next
            // null     1   <-   2   <-   3        4   ->   null
        }

        //                                        prev     current
        // null   <-   1   <-   2   <-   3   <-   4        null
        return prev;
    }

}
