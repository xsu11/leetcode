package com.xinsu.lcr;

/**
 * 一个专业的小偷，计划偷窃一个环形街道上沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋
 * 是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组 nums ，请计算 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 示例 2：
 *
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 *      偷窃到的最高金额 = 1 + 3 = 4 。
 * 示例 3：
 *
 * 输入：nums = [0]
 * 输出：0
 *
 *
 * 提示：
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 *
 *
 * 注意：本题与主站 213 题相同： https://leetcode-cn.com/problems/house-robber-ii/
 */

public class LCR090_HouseRobberII {

    public int rob(int[] nums) {
        // f(i) = max(f(i-2) + nums[i], f(i-1))
        // from either [1, n-1] or [0, n-2]

        // boundary case
        if (nums.length == 0) {
            return 0;
        }

        if (nums.length == 1) {
            return nums[0];
        }

        // nums.length >= 1

        return Math.max(f(nums, 0, nums.length - 2), f(nums, 1, nums.length - 1));
    }

    private int f(final int[] nums, final int begin, final int end) {
        final int length = end - begin + 1;
        if (length == 0) {
            return 0;
        }

        if (length == 1) {
            return nums[begin];
        }

        if (length == 2) {
            return Math.max(nums[begin], nums[begin + 1]);
        }

        // length >= 2

        int i_2 = nums[begin];
        int i_1 = Math.max(nums[begin], nums[begin + 1]);
        int i_max = i_1;

        for (int i = begin + 1; i < end + 1; i++) {
            i_max = Math.max(i_2 + nums[i], i_1);

            // update i_2/i_1
            i_2 = i_1;
            i_1 = i_max;
        }

        return i_max;
    }

}
