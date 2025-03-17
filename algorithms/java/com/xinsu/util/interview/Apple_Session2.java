package com.xinsu.util.interview;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * 两数之和：给定一个整数数组 nums 和一个目标值 target，找出数组中和为 target 的两个数。
 * 你可以假设每个输入只有唯一的解，并且你不可以重复使用数组中的相同元素。
 */

public class Apple_Session2 {

    public List<Integer> twoSum(final int[] nums, final int target) {
        // boundary case
        if (nums.length == 0) {
            return Collections.emptyList();
        }

        final Set<Integer> solved = solve(nums);
        return find(nums, target, solved);
    }

    private Set<Integer> solve(final int[] nums) {
        final Set<Integer> solved = new HashSet<>();
        for (final int num: nums) {
            solved.add(num);
        }
        return solved;
    }

    private List<Integer> find(final int[] nums, final int target, final Set<Integer> solved) {
        for (final int num: nums) {
            final int another = target - num;
            if (solved.contains(another)) {
                return Arrays.asList(num, another);
            }
        }

        return Collections.emptyList();
    }

}
