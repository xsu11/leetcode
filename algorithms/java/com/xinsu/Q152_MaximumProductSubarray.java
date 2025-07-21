package com.xinsu;

/**
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 *
 * 测试用例的答案是一个 32-位 整数。
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 示例 2:
 *
 * 输入: nums = [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 *
 * 提示:
 *
 * 1 <= nums.length <= 2 * 104
 * -10 <= nums[i] <= 10
 * nums 的任何子数组的乘积都 保证 是一个 32-位 整数
 */

public class Q152_MaximumProductSubarray {

    public int maxProduct(int[] nums) {
        long maxF = nums[0];
        long minF = nums[0];

        int result = nums[0];

        for (int i = 1; i < nums.length; i++) {
            long maxF_1 = maxF;
            long minF_1 = minF;

            maxF = Math.max(maxF_1 * nums[i], Math.max(minF_1 * nums[i], nums[i]));
            minF = Math.min(minF_1 * nums[i], Math.min(maxF_1 * nums[i], nums[i]));

            // since minF is long, it might be smaller than the minimum value of a 32-bit signed int: -2147483648
            if (minF < -1<<31) {
                minF = nums[i]; // discard previous product and reset minF to only contains nums[i]
            }

            result = Math.max(result, (int) maxF);
        }

        return result;
    }

}
