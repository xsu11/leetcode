package com.xinsu;

import com.xinsu.util.ListNode;

public class Q206_ReverseLinkedList {

    public ListNode reverseList(ListNode head) {
        // bottom-up condition
        if (head == null || head.next == null) {
            return head;
        }

        //                   head
        // 1   ->   2   ->   3   ->   (4   ->   5   ->   6   ->   null)

        final ListNode newHead = reverseList(head.next);

        //                   head                        newHead
        // 1   ->   2   ->   3   ->   (4   <-   5   <-   6)

        head.next.next = head;
        head.next = null;

        //                   head                       newHead
        // 1   ->   2   ->   3   <-   4   <-   5   <-   6

        return newHead;
    }

}
