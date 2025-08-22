package com.xinsu;

import java.util.HashSet;
import java.util.Set;

/**
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 *
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 示例 2：
 *
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 示例 3：
 *
 * 输入：nums = [1,0,1,2]
 * 输出：3
 *
 *
 * 提示：
 *
 * 0 <= nums.length <= 105
 * -109 <= nums[i] <= 109
 */
public class Q128_LongestConsecutiveSequence {

    public int longestConsecutive(int[] nums) {
        // boundary case
        if (nums.length < 2) {
            return nums.length;
        }

        final Set<Integer> solved = solve(nums);
        return check(solved);
    }

    private Set<Integer> solve(int[] nums) {
        final Set<Integer> solved = new HashSet<>();
        for (final int n : nums) {
            solved.add(n);
        }
        return solved;
    }

    private int check(Set<Integer> solved) {
        int maxlength = 1;
        for (final int n : solved) {
            if (!solved.contains(n - 1)) {
                // n could be a new beginning of a consecutive sequence
                int cur = n;
                int length = 1;
                while (solved.contains(cur + 1)) {
                    cur++;
                    length++;
                }

                if (maxlength < length) {
                    maxlength = length;
                }
            }
        }

        return maxlength;
    }

}
