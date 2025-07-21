package com.xinsu;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组
 * [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * 你可以按 任意顺序 返回答案 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 示例 2：
 *
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 *
 *
 * 提示：
 *
 * 1 <= nums.length <= 200
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 */

public class Q18_4Sum {

    public List<List<Integer>> fourSum(int[] nums, int target) {
        // boundary case
        final int n = nums.length;
        if (n < 4) {
            return Collections.emptyList();
        }

        Arrays.sort(nums);

        final List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < n - 3; i++) {
            // short circuit
            {
                if (i > 0 && nums[i - 1] == nums[i]) {
                    continue;
                }

                final long actual_i = (long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
                if (actual_i > target) {
                    // no more combinations = target, just return
                    break;
                }

                final long actual_n = (long) nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1];
                if (actual_n < target) {
                    // no valid combination for this i, maybe next loop
                    continue;
                }
            }

            for (int j = i + 1; j < n - 2; j++) {
                // short circuit
                {
                    if (j > i + 1 && nums[j - 1] == nums[j]) {
                        continue;
                    }

                    final long actual_j = (long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                    if (actual_j > target) {
                        // no more combinations = target, just return
                        break;
                    }

                    final long actual_n = (long) nums[i] + nums[j] + nums[n - 2] + nums[n - 1];
                    if (actual_n < target) {
                        // no valid combination for this j, maybe next loop
                        continue;
                    }
                }

                // use two pointers
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    final long actual = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (actual < target) {
                        left++;
                    } else if (actual > target) {
                        right--;
                    } else { // actual >== target
                        // a valid combination is found, add to result
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));

                        // skip duplicates of nums[left] and nums[right]
                        left++;
                        while (left < right && nums[left - 1] == nums[left]) {
                            left++;
                        }
                    }
                }
            }
        }

        return result;
    }

}
