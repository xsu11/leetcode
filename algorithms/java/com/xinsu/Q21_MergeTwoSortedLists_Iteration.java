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

public class Q21_MergeTwoSortedLists_Iteration {

    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        // boundary case
        if (list1 == null) {
            return list2;
        }

        if (list2 == null) {
            return list1;
        }

        // create dummy and point to smaller node of list1/list2
        final ListNode dummy = new ListNode(0, list1.val <= list2.val ? list1 : list2);
        ListNode cur = dummy;

        /*
         *                     list1
         *                 >   1   >   3  ->   4  ->   null
         * dummy/cur     /
         *
         *                     2   ->   4  ->   5  ->   null
         *                     list2
         */

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                cur.next = list1;
                list1 = list1.next;
            } else {
                cur.next = list2;
                list2 = list2.next;
            }

            // step forward
            cur = cur.next;

            /*
             *                      list1
             *          cur     >   3  ->   4  ->   null
             * dummy -> 1     /
             *                      2   ->   4  ->   5  ->   null
             *                      list2
             */

            /*
             *                               list1
             *                   cur         3  ->   4  ->   null
             * dummy -> 1   ->   2     \
             *                           >   4  ->   5  ->   null
             *                               list2
             */

            /*
             *                                       list1
             *                           cur     >   4  ->   null
             * dummy -> 1   ->   2  ->   3     /
             *                                       4  ->   5  ->   null
             *                                       list2
             */

            /*
             *                                                list1
             *                                    cur     >   null
             * dummy -> 1   ->   2  ->   3   ->   4     /
             *                                                4  ->   5  ->   null
             *                                                list2
             */
        }

        // when two lists' length are not equal, cur points to the end node of the shorter one,
        // need to concat the longer list to cur.next
        cur.next = list1 == null ? list2 : list1;

        /*
         *                                    cur
         * dummy -> 1   ->   2  ->   3   ->   4   ->   4   ->   5   ->   null
         *                                             list2
         */

        return dummy.next;
    }

}
