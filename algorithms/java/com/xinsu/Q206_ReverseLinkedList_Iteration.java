package com.xinsu;

import com.xinsu.util.ListNode;

/*
 * Given the head of a singly linked list, reverse the list, and return the reversed list.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
 * Example 3:
 *
 * Input: head = []
 * Output: []
 *
 *
 * Constraints:
 *
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Vertex.val <= 5000
 */

public class Q206_ReverseLinkedList_Iteration {

    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode prev = null;
        ListNode cur = head;

        // prev     cur
        //          1   ->   2   ->   3   ->   4   ->   5   ->   null
        while (cur != null) {
            final ListNode next = cur.next;

            //          prev     cur     next
            // 1   <-   2        3   ->   4   ->   5   ->   null

            // reverse cur
            cur.next = prev;

            // step forward
            prev = cur;
            cur = next;

            //                   prev     cur
            // 1   <-   2   <-   3        4   ->   5   ->   null
        }

        //                                     prev     cur
        // 1   <-   2   <-   3   <-   4   <-   5        null

        return prev;
    }

}
