package com.xinsu;

import com.xinsu.util.ListNode;

/*
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two
 * lists.
 *
 * Return the head of the merged linked list.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 * Example 2:
 *
 * Input: list1 = [], list2 = []
 * Output: []
 * Example 3:
 *
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 *
 * Constraints:
 *
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
 */

public class Q21_MergeTwoSortedLists_Recursion {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // bottom-up condition
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }

        final ListNode head = list1.val <= list2.val ? list1 : list2;
        /*
         *                  head
         *                  1   ->   2   ->   4   ->   null
         * x -> y -> z
         *                  2   ->   3   ->   5   ->   null
         */

        final ListNode other = list1.val <= list2.val ? list2: list1;
        /*
         *                             head.next
         *                head    ->   2   ->   4   ->   null
         * x -> y -> z    1     /
         *                             2   ->   3   ->   5   ->   null
         *                             other
         */

        head.next = mergeTwoLists(head.next, other);
        /*
         *                    head
         * x -> y -> z        1 -> 2 -> 2 -> 3 -> 4 -> 5   ->   null
         */

        return head;
        /*
         * after return, previous recursion connects its head to this returned "head"
         *           previous head
         * x -> y -> z   ->   1 -> 2 -> 2 -> 3 -> 4 -> 5   ->   null
         */
    }

}
