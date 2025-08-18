package com.xinsu;

/**
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 * 示例 2：
 *
 * 输入：nums = [1]
 * 输出：1
 * 示例 3：
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 * 提示：
 *
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 */
public class Q53_MaximumSubarray {

    /**
     * f(i) = max(f(i-1) + nums[i], nums[i])
     *
     * if nums[i] is to large, this needs to return a long, or even a string to represent large integer
     */
    public int maxSubArray(int[] nums) {
        // boundary case
        if (nums.length == 0) {
            return 0;
        }

        if (nums.length == 1) {
            return nums[0];
        }

        int maxSum = Integer.MIN_VALUE;

        int i_1 = 0;
        for (final int n : nums) {
            final int i = Math.max(i_1 + n, n);
            if (maxSum < i) {
                maxSum = i;
            }

            i_1 = i;
        }

        return maxSum;
    }

}
