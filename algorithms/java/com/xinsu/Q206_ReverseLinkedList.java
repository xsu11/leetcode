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
 * -5000 <= Node.val <= 5000
 */

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

        //                    head                       newHead
        // 1   ->   2   ->   (3   <-   4   <-   5   <-   6)

        return newHead;
    }

}
