package com.xinsu;

import java.util.Arrays;

/**
 * 给你一个长度为 n 的整数数组 nums ，返回使所有数组元素相等需要的最小操作数。
 *
 * 在一次操作中，你可以使数组中的一个元素加 1 或者减 1 。
 *
 * 测试用例经过设计以使答案在 32 位 整数范围内。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,2,3]
 * 输出：2
 * 解释：
 * 只需要两次操作（每次操作指南使一个元素加 1 或减 1）：
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 示例 2：
 *
 * 输入：nums = [1,10,2,9]
 * 输出：16
 *
 *
 * 提示：
 *
 * n == nums.length
 * 1 <= nums.length <= 105
 * -109 <= nums[i] <= 109
 */
public class Q462_MinimumMovesToEqualArrayElementsII_Sort {

    public int minMoves2(int[] nums) {
        // boundary case
        if (nums.length < 2) {
            return 0;
        }

        final int midN = getMidN(nums);

        int result = 0;
        for (final int n : nums) {
            result += Math.abs(n - midN);
        }

        return result;
    }

    private int getMidN(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length / 2];
    }

}
