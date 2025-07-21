package com.xinsu;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/*
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k,
 * and j != k, and nums[i] + nums[j] + nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 * Example 2:
 *
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 * Example 3:
 *
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 *
 * Constraints:
 *
 * 3 <= nums.length <= 3000
 * -105 <= nums[i] <= 105
 */

public class Q15_3Sum {

    public List<List<Integer>> threeSum(int[] nums) {
        if (nums.length < 3) {
            return Collections.emptyList();
        }

        Arrays.sort(nums);

        final List<List<Integer>> result = new ArrayList<>();

        // traverse nums from beginning to nums[nums.length - 3], and only find other two on the right
        // since nums has been sorted, only traverse non-positives
        for (int i = 0; i < nums.length - 2 && nums[i] <= 0; i++) {
            // use two pointers
            int begin = i + 1;
            int end = nums.length - 1;

            while (begin < end) {
                final int actual = nums[i] + nums[begin] + nums[end];
                if (actual < 0) {
                    begin++;
                } else if (actual > 0) {
                    end--;
                } else { // nums[begin] + nums[end] + nums[i] = 0
                    // found a combination, add to result
                    result.add(Arrays.asList(nums[i], nums[begin], nums[end]));

                    // skip all elements from next to begin in nums that equals to nums[begin] to avoid duplicate
                    // WARNING: ONLY skip when found a combination
                    while (begin < end && nums[begin] == nums[begin + 1]) {
                        begin++;
                    }

                    // now nums[begin] is the last element that has the same value, move forward
                    begin++;
                }
            }

            // skip all elements from next to i in nums that equals to nums[i] to avoid duplicate
            while (i < nums.length - 2 && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return result;
    }

}
