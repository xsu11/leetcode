package com.xinsu.lcr;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a ，b ，c ，使得 a + b + c = 0 ？请找出所有和为 0 且 不重复 的三元组。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 示例 2：
 *
 * 输入：nums = []
 * 输出：[]
 * 示例 3：
 *
 * 输入：nums = [0]
 * 输出：[]
 *
 *
 * 提示：
 *
 * 0 <= nums.length <= 3000
 * -105 <= nums[i] <= 105
 *
 *
 * 注意：本题与主站 15 题相同：https://leetcode-cn.com/problems/3sum/
 */

public class LCR007_3Sum {

    public List<List<Integer>> threeSum(int[] nums) {
        // boundary case
        if (nums.length < 3) {
            return Collections.emptyList();
        }

        Arrays.sort(nums);

        final List<List<Integer>> result = new ArrayList<>();

        int i = 0;
        while (i < nums.length - 1 && nums[i] <= 0) {
            // use two pointers
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                final int actual = nums[i] + nums[left] + nums[right];
                if (actual < 0) {
                    left++;
                } else if (actual > 0) {
                    right--;
                } else { // actual == 0
                    // found a solution, add to result
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));

                    left++;

                    // skip all duplicates from left
                    // WARNING: make sure left is valid
                    while (left < right && nums[left - 1] == nums[left]) {
                        left++;
                    }
                }
            }

            i++;

            // skip all duplicates from i
            // WARNING: need to make sure i is valid
            while (i < nums.length - 1 && nums[i - 1] == nums[i]) {
                i++;
            }
        }

        return result;
    }

}
