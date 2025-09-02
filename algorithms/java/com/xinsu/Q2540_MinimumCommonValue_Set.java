package com.xinsu;

import java.util.HashSet;
import java.util.Set;

/**
 * 给你两个整数数组 nums1 和 nums2 ，它们已经按非降序排序，请你返回两个数组的 最小公共整数 。
 * 如果两个数组 nums1 和 nums2 没有公共整数，请你返回 -1 。
 *
 * 如果一个整数在两个数组中都 至少出现一次 ，那么这个整数是数组 nums1 和 nums2 公共 的。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,2,3], nums2 = [2,4]
 * 输出：2
 * 解释：两个数组的最小公共元素是 2 ，所以我们返回 2 。
 * 示例 2：
 *
 * 输入：nums1 = [1,2,3,6], nums2 = [2,3,4,5]
 * 输出：2
 * 解释：两个数组中的公共元素是 2 和 3 ，2 是较小值，所以返回 2 。
 *
 *
 * 提示：
 *
 * 1 <= nums1.length, nums2.length <= 105
 * 1 <= nums1[i], nums2[j] <= 109
 * nums1 和 nums2 都是 非降序 的。
 */
public class Q2540_MinimumCommonValue_Set {

    public int getCommon(int[] nums1, int[] nums2) {
        // boundary case
        if (nums1.length == 0 && nums2.length == 0) {
            return -1;
        }

        final int[] toSolve;
        final int[] toCheck;
        if (nums1.length < nums2.length) {
            toSolve = nums1;
            toCheck = nums2;
        } else {
            toSolve = nums2;
            toCheck = nums1;
        }

        final Set<Integer> solved = solve(toSolve);
        return check(solved, toCheck);
    }

    private Set<Integer> solve(int[] toSolve) {
        final Set<Integer> solved = new HashSet<>();
        for (final int n : toSolve) {
            solved.add(n);
        }
        return solved;
    }

    /**
     * if the input nums array is not sorted, use a minN to record the minimum value
     */
    private int check(Set<Integer> solved, int[] toCheck) {
        int minN = Integer.MAX_VALUE;
        for (int n : toCheck) {
            if (solved.contains(n) && n < minN) {
                minN = n;
            }
        }

        return minN != Integer.MAX_VALUE ? minN : -1;
    }

}
