package com.xinsu.lcr;

import java.util.HashMap;
import java.util.Map;

/**
 * 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
 *
 *
 *
 * 示例 1：
 *
 * 输入: nums = [0,1]
 * 输出: 2
 * 解释: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
 * 示例 2：
 *
 * 输入: nums = [0,1,0]
 * 输出: 2
 * 解释: [0, 1] (或 [1, 0]) 是具有相同数量 0 和 1 的最长连续子数组。
 *
 *
 * 提示：
 *
 * 1 <= nums.length <= 105
 * nums[i] 不是 0 就是 1
 *
 *
 * 注意：本题与主站 525 题相同： https://leetcode-cn.com/problems/contiguous-array/
 */

public class LCR011_ContiguousArray {

    public int findMaxLength(int[] nums) {
        /*
         * Replace all 0s with -1 in a subarray that contains equal number of 0 and 1, then this subarray's sum becomes 0. Then
         * this problem becomes a case of LCR010.
         *
         * a1, a2, a3, ..., ai, ..., aj, ..., an-1
         * if sum[0, j] - sum[0, i] == 0, then subarray [i+1, j]'s length is j - (i+1) + 1 = j - i
         *
         * Since max length of subarray is required, use a map to store the sum and the index of its first appearance.
         */

        // sum -> index of its first appearance
        final Map<Integer, Integer> sumFirst = new HashMap<>();
        sumFirst.put(0, -1); // initially no num is calculated, the sum is 0 with index as a dummy -1

        int sum = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.length; i++) {
            // if this i-th num is 0, replace it with -1 then add to sum
            sum += nums[i] == 0 ? -1 : 1;

            // now sumFirst stores all sums before this num
            if (sumFirst.containsKey(sum)) {
                // found a subarray, update maxLength if needed
                final int length = i - sumFirst.get(sum);
                if (maxLength < length) {
                    maxLength = length;
                }
            } else {
                sumFirst.put(sum, i);
            }
        }

        return maxLength;
    }

}
