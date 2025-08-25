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
     * for the i-th e in nums:
     * 1. if f(i-1) >= 0 && nums[i] >= 0, adding nums[i] increases the sum (f(i-1) + nums[i]) and length (i),
     * 2. if f(i-1) >= 0 && nums[i] < 0, although adding nums[i] decreases the sum, but it still might belong to the longest sequence with the max sum.
     *
     * 3. if f(i-1) < 0 && nums[i] >= 0, adding f(i-1) contributes nothing to the sum, therefore nums[i] can be a beginning of a new sequence.
     * 4. if f(i-1) < 0 && nums[i] < 0, nums[i] can be a beginning of a new sequence.
     *
     * f(i) = f(i-1) + nums[i], f(i-1) >= 0
     * f(i) = nums[i], f(i-1) < 0
     *
     * if nums[i] is too large, this needs to return a long, or even a string to represent large integer
     */
    public int maxSubArray(int[] nums) {
        // boundary case
        if (nums.length == 0) {
            return 0;
        }

        if (nums.length == 1) {
            return nums[0];
        }

        // initially set to min value as the sum might be negative
        int maxSum = Integer.MIN_VALUE;

        int sum_1 = 0;
        for (int i = 0; i < nums.length; i++) {
            final int sum = sum_1 >= 0 ? sum_1 + nums[i] : nums[i];

            if (maxSum < sum) {
                maxSum = sum;
            }

            sum_1 = sum;
        }

        return maxSum;
    }

}
