package com.xinsu;

import java.util.Deque;
import java.util.LinkedList;

/**
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * 示例 2：
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 * 提示：
 *
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
 * 1 <= k <= nums.length
 */
public class Q239_SlidingWindowMaximum {

    public int[] maxSlidingWindow(int[] nums, int k) {
        // boundary case
        if (nums.length == 0 || k <= 0) {
            return new int[0];
        }

        // Doube queue storing index of nums
        // maintaining a desc order from head to tail
        // head's index may < left bound of k window
        final Deque<Integer> deque = new LinkedList<>();

        // traverse first k ns
        for (int i = 0; i < k; i++) {
            while (!deque.isEmpty() && nums[deque.peekLast()] <= nums[i]) {
                deque.pollLast();
            }
            deque.offerLast(i);
        }

        // 1
        // 3
        // 3 -1

        final int[] result = new int[nums.length - k + 1];
        result[0] = nums[deque.peekFirst()];

        for (int i = k; i < nums.length; i++) {
            // first, poll all smaller ns from deque
            while (!deque.isEmpty() && nums[deque.peekLast()] <= nums[i]) {
                deque.pollLast();
            }

            // offer i into deque to maintain desc order
            deque.offerLast(i);

            final int leftBound =  i - k + 1;

            // next, poll all indexes < left bound of k window from deque
            while (deque.peekFirst() < leftBound) {
                deque.pollFirst();
            }

            // now current head is the index of max n
            result[leftBound] = nums[deque.peekFirst()];
        }

        // 3 -1 -3
        // 3 -1
        // 3
        //
        // 5
        // 5 3
        // 5
        //
        // 6
        //
        // 7

        return result;
    }

}
