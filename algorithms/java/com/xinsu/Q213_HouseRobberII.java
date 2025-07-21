package com.xinsu;

/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
 * stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two
 * adjacent houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you
 * can rob tonight without alerting the police.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
 * Example 2:
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 * Example 3:
 *
 * Input: nums = [1,2,3]
 * Output: 3
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 */

public class Q213_HouseRobberII {

    public int rob(int[] nums) {
        // boundary case
        if (nums.length == 0) {
            return 0;
        }

        if (nums.length == 1) {
            return nums[0];
        }

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

        // length > 2

        int i_2 = nums[begin];
        int i_1 = Math.max(nums[begin], nums[begin + 1]);
        int i_max = i_1;

        for (int i = begin + 2; i < end + 1; i++) {
            i_max = Math.max(i_2 + nums[i], i_1);

            // update i_2/i_1
            i_2 = i_1;
            i_1 = i_max;
        }

        return i_max;
    }

}
