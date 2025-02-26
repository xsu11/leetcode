package com.xinsu;

import com.xinsu.util.ListNode;

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

            cur.next = prev;
            prev = cur;

            // step forward
            cur = next;

            //                   prev     cur
            // 1   <-   2   <-   3        4   ->   5   ->   null
        }

        //                                     prev     cur
        // 1   <-   2   <-   3   <-   4   <-   5        null

        return prev;
    }

}
