package com.xinsu;

import java.util.ArrayList;
import java.util.List;

/*
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip
 * at most k 0's.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 * Example 2:
 *
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 105
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 */

public class Q1004_MaxConsecutiveOnesIII {

    public int longestOnes(int[] nums, int k) {
        // boundary case
        if (nums.length == 0 || k < 0) {
            return 0;
        }

        // if k is larger than nums length, simply return
        if (k >= nums.length) {
            return nums.length;
        }

        int maxOnes = 0;

        // [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
        // -1   0 1 4 5 9 12 13 14  19
        final List<Integer> zeros = getZeros(nums);

        // WARNING: k also might be larger than zero counts in nums
        if (k >= zeros.size() - 2) {
            return nums.length;
        }

        // traverse with window
        int left = 1;
        int right = k;
        while (right < zeros.size() - 1) {
            // 0,1,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1
            final int ones = zeros.get(right + 1) - zeros.get(left - 1) - 1;

            // update max length if possible
            if (maxOnes < ones) {
                maxOnes = ones;
            }

            left++;
            right++;
        }

        return maxOnes;
    }

    private static List<Integer> getZeros(int[] nums) {
        final List<Integer> zeros = new ArrayList<>();
        zeros.add(-1);
        // create array for all 0's index
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                // sve to the array
                zeros.add(i);
            }
        }
        zeros.add(nums.length);
        return zeros;
    }

}
