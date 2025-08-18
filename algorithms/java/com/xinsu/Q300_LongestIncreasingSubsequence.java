package com.xinsu;

/**
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 *
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 *
 *
 * 示例 1：
 *
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 示例 2：
 *
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 * 示例 3：
 *
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 *
 *
 * 提示：
 *
 * 1 <= nums.length <= 2500
 * -104 <= nums[i] <= 104
 *
 *
 * 进阶：
 *
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 */
public class Q300_LongestIncreasingSubsequence {

    public int lengthOfLIS(int[] nums) {
        // boundary case
        if (nums.length == 0) {
            return 0;
        }

        final int[] d = new int[nums.length + 1];
        d[0] = Integer.MIN_VALUE;
        d[1] = nums[0];

        int maxLength = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > d[maxLength]) {
                d[maxLength + 1] = nums[i];
                maxLength++;
            } else {
                final int found = search(d, 1, maxLength, nums[i]);
                d[found + 1] = nums[i];
            }
        }

        return maxLength;
    }

    /**
     * find the index of the closest e in d that < n
     * d[0] is dummy e which is always < n
     * left >= 1, right < d.length, which is nums.length + 1
     * if not found return index 0
     */
    // private int search(int[] d, int left, int right, int n) {
    //     int found = 0;
    //     while (left <= right) {
    //         final int mid = left + (right - left) / 2;
    //         if (d[mid] < n) {
    //             found = mid;
    //             left = mid + 1;
    //         } else { // n <= d[mid]
    //             right = mid - 1;
    //         }
    //     }

    //     return found;
    // }

    private int search(int[] d, int left, int right, int n) {
        // bottom-up condition
        if (left > right) {
            return 0;
        }

        // recursion
        final int mid = left + (right - left) / 2;
        if (d[mid] < n) {
            // closest e < n must lie in the right half
            if (d[mid + 1] > n) {
                // found
                return mid;
            } else {
                return search(d, mid + 1, right, n);
            }
        } else {
            // closest e < n must lie in the left half
            if (d[mid - 1] < n) {
                // found
                return mid - 1;
            } else {
                return search(d, left, mid - 1, n);
            }
        }
    }

}
