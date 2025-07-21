package com.xinsu.lcr;

/**
 * 给定一个正整数数组 nums和整数 k ，请找出该数组内乘积小于 k 的连续的子数组的个数。
 *
 *
 *
 * 示例 1：
 *
 * 输入: nums = [10,5,2,6], k = 100
 * 输出: 8
 * 解释: 8 个乘积小于 100 的子数组分别为: [10], [5], [2], [6], [10,5], [5,2], [2,6], [5,2,6]。
 * 需要注意的是 [10,5,2] 并不是乘积小于100的子数组。
 * 示例 2：
 *
 * 输入: nums = [1,2,3], k = 0
 * 输出: 0
 *
 *
 * 提示：
 *
 * 1 <= nums.length <= 3 * 104
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 106
 *
 *
 * 注意：本题与主站 713 题相同：https://leetcode-cn.com/problems/subarray-product-less-than-k/
 */

public class LCR009_SubarrayProductLessThanK {

    public int numSubarrayProductLessThanK(int[] nums, int k) {
        // boundary case
        if (nums.length == 0 || k <= 0) {
            return 0;
        }

        // k > 0

        int count = 0;

        int left = 0;
        int product = 1;

        /*
         * invariant:
         * 1. all subarrays ending with right needs to be validated
         * 2. left < right: then [left, right - 1]'s product < k,
         * or left == right: no subarray is found from last loop
         *
         * every loop validates all subarrays ending with right, move left forward to the position where [left, right]'s
         * product < k
         */
        for (int right = 0; right < nums.length; right++) {
            // expand product to get current product of [left, right]
            product *= nums[right];

            /*
             * since right has been moved forward, needs to move left forward to shrink product until
             * left > right or product < k
             */

            while (left <= right && product >= k) {
                // move left forward to shrink product
                left++;
                product /= nums[left - 1];
            }

            // left > right || product < k

            if (left <= right && product < k) {
                // found a subarray, every subarray ending with right of this subarray counts to the result
                // 12345: 12345,2345,345,45,5
                count += right - left + 1;
            } // else, left == right + 1, finish counting all subarrays ending with right, process next loop
        }

        return count;
    }

}
