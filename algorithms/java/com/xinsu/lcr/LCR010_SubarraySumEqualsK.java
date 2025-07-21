package com.xinsu.lcr;

import java.util.HashMap;
import java.util.Map;

/**
 * 给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。
 *
 *
 *
 * 示例 1：
 *
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2
 * 解释: 此题 [1,1] 与 [1,1] 为两种不同的情况
 * 示例 2：
 *
 * 输入:nums = [1,2,3], k = 3
 * 输出: 2
 *
 *
 * 提示:
 *
 * 1 <= nums.length <= 2 * 104
 * -1000 <= nums[i] <= 1000
 * -107 <= k <= 107
 *
 *
 *
 * 注意：本题与主站 560 题相同： https://leetcode-cn.com/problems/subarray-sum-equals-k/
 */

public class LCR010_SubarraySumEqualsK {

    public int subarraySum(int[] nums, int k) {
        /*
         * a1, a2, a3, ..., ai, ..., aj, ..., an-1
         * if sum[0, j] - sum[0, i] == k, then subarray [i+1, j]'s sum is k
         *
         * Use a map to store sum[0, i] and how many times this sum appears, then:
         * for each i-th num, this map stores all sums before this i-th num
         */

        // sum -> count of appearance
        final Map<Integer, Integer> sumCount = new HashMap<>();
        sumCount.put(0, 1); // initially no num is calculated, the sum is 0

        int sum = 0;
        int count = 0;
        for (final int num : nums) {
            sum += num;

            // now sumCount stores all sums before this num
            count += sumCount.getOrDefault(sum - k, 0);

            // then put sum of this num into sumCount for next loop
            sumCount.put(sum, sumCount.getOrDefault(sum, 0) + 1);
        }

        return count;
    }

}
