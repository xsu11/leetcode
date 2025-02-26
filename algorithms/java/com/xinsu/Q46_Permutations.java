package com.xinsu;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

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

    private void generatePermutations(int[] nums, int start, List<List<Integer>> result) {
        // bottom-up condition
        if (start == nums.length - 1) {
            // last num, generated a permutation, add to result
            result.add(toList(nums));
            return;
        }

        for (int i = start; i < nums.length; i++) {
            swap(nums, start, i);
            generatePermutations(nums, start + 1, result);
            swap(nums, start, i);
        }
    }

    private List<Integer> toList(int[] nums) {
        final List<Integer> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            list.add(nums[i]);
        }
        return list;
    }

    private void swap(int[] nums, int i, int j) {
        final int t = nums[j];
        nums[j] = nums[i];
        nums[i] = t;
    }

}
