package com.xinsu.lcr;

/**
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 *
 * 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子
 * 数组，返回 0 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 示例 2：
 *
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 * 示例 3：
 *
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 *
 *
 * 提示：
 *
 * 1 <= target <= 109
 * 1 <= nums.length <= 105
 * 1 <= nums[i] <= 105
 *
 *
 * 进阶：
 *
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
 *
 *
 * 注意：本题与主站 209 题相同：https://leetcode-cn.com/problems/minimum-size-subarray-sum/
 */

public class LCR008_MinimumSizeSubarraySum {

    public int minSubArrayLen(int target, int[] nums) {
        // boundary case
        if (nums.length == 0 || target <= 0) {
            return 0;
        }

        // target > 0

        int minLength = nums.length + 1;

        // use two pointers
        int left = 0;
        int right = 0;

        int sum = nums[0];

        /*
         * invariant:
         * 1. right < nums.length
         * 2. [left, right] is the subarray that needs to check
         * 3. sum is the result of [left, right]
         */
        while (left < nums.length && right < nums.length) {
            if (sum >= target) {
                // left must be <= right
                // found a subarray, update minLength if needed
                final int length = right - left + 1;
                if (length < minLength) {
                    minLength = length;
                }

                left++;
                // shrink sum
                sum -= nums[left - 1];
            } else {
                // if left = right + 1, sum is 0 and must be < target,
                // code comes into this else to move right forward
                right++;

                // expand sum
                // WARNING: need to check right before use
                if (right < nums.length) {
                    sum += nums[right];
                }
            }
        }

        return minLength <= nums.length ? minLength : 0;
    }

}
