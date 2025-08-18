package com.xinsu;

import java.util.Arrays;

/**
 * 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
 *
 * 返回这三个数的和。
 *
 * 假定每组输入只存在恰好一个解。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2)。
 * 示例 2：
 *
 * 输入：nums = [0,0,0], target = 1
 * 输出：0
 * 解释：与 target 最接近的和是 0（0 + 0 + 0 = 0）。
 *
 *
 * 提示：
 *
 * 3 <= nums.length <= 1000
 * -1000 <= nums[i] <= 1000
 * -104 <= target <= 104
 */
public class Q16_3SumClosest {

    public int threeSumClosest(int[] nums, int target) {
        // boundary case
        if (nums.length < 3) {
            return 0;
        }

        Arrays.sort(nums);

        int best = Integer.MAX_VALUE;
        int i = 0;
        while (i < nums.length) {
            // use two pointers
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                final int actual = nums[i] + nums[left] + nums[right];

                if (actual == target) {
                    return target;
                }

                int actualDiff = Math.abs(target - actual);
                int bestDiff = Math.abs(target - best);
                if (actualDiff < bestDiff) {
                    best = actual;
                }

                if (actual > target) {
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else {
                    left++;
                    while (left < right && nums[left - 1] == nums[left]) {
                        left++;
                    }
                }
            }

            i++;
            while (i < nums.length && nums[i - 1] == nums[i]) {
                i++;
            }
        }

        return best;
    }

}
