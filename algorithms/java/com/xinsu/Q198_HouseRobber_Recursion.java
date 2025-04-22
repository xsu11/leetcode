package com.xinsu;

/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money
 * stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems
 * connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each house, return the maximum amount of money you
 * can rob tonight without alerting the police.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 * Example 2:
 *
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 */

public class Q198_HouseRobber_Recursion {

    public int rob(int[] nums) {
        // boundary case
        if (nums.length == 0) {
            return 0;
        }

        return f(nums, nums.length - 1);
    }

    // i: index of nums
    // f(i): maximum value of robbing house 0 to i, 0 <= i <= nums.length - 1
    private int f(final int[] nums, final int i) {
        // boundary case
        if (i == 1) {
            return Math.max(nums[0], nums[1]);
        }

        if (i == 0) {
            return nums[0];
        }

        // i > 1, that is nums.length > 2

        // f(i) = max(f(i-2) + nums[i], f(i-1))
        return Math.max(f(nums, i - 2) + nums[i], f(nums, i - 1));
    }

}
