package com.xinsu;

import java.util.PriorityQueue;

/**
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 * 示例 2:
 *
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 * 提示：
 *
 * 1 <= k <= nums.length <= 105
 * -104 <= nums[i] <= 104
 */

public class Q215_KthLargestElementInAnArray {

    public int findKthLargest(int[] nums, int k) {
        // boundary case
        if (k <= 0) {
            // log
            return 0;
        }

        // min heap by default
        final PriorityQueue<Integer> minHeap = new PriorityQueue<>((a, b) -> a - b);
        for (final int n : nums) {
            if (minHeap.size() < k) {
                minHeap.offer(n);
            } else if (n > minHeap.peek()) { // minHeap.size() == k
                // compare n with heap top, if n is larger, remove top and insert n
                minHeap.poll();
                minHeap.offer(n);
            } // else, discard n as it is not within k-th largest es
        }

        return minHeap.peek();
    }

}
