package com.xinsu;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/*
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 *
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 *
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 */

public class Q46_Permutations {

    public List<List<Integer>> permute(int[] nums) {
        // boundary case
        if (nums.length == 0) {
            return Collections.emptyList();
        }

        final List<List<Integer>> result = new ArrayList<>();
        generatePermutations(nums, 0, result);
        return result;
    }

    // start: the start index of the range in nums that has not been added to current permutation result
    private void generatePermutations(
            final int[] nums,
            final int start,
            final List<List<Integer>> result) {
        // bottom-up condition
        if (start == nums.length - 1) {
            // last num, just append to generate a permutation, add to result
            result.add(toList(nums));
            return;
        }

        // from start to the end of nums, these are the elements that has not been traversed yet
        for (int i = start; i < nums.length; i++) {
            swap(nums, start, i);
            // after swap start with the i-th element, generate all permutations from start+1 to the end of nums
            generatePermutations(nums, start + 1, result);
            // then swap back for next loop
            swap(nums, start, i);
        }
    }

    private List<Integer> toList(int[] nums) {
        final List<Integer> list = new ArrayList<>();
        for (int num : nums) {
            list.add(num);
        }
        return list;
    }

    private void swap(int[] nums, int i, int j) {
        final int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
    }

}
