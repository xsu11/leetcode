package com.xinsu;

/*
 * There is an integer array nums sorted in ascending order (with distinct values).
 *
 * Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length)
 * such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
 *
 * Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums,
 * or -1 if it is not in nums.
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 *
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 *
 * Input: nums = [1], target = 0
 * Output: -1
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 5000
 * -104 <= nums[i] <= 104
 * All values of nums are unique.
 * nums is an ascending array that is possibly rotated.
 * -104 <= target <= 104
 */

public class Q33_SearchInRotatedSortedArray {

    public int search(final int[] nums, final  int target) {
        return doSearch(nums, target, 0, nums.length - 1);
    }

    private int doSearch(final int[] nums, final int target, final int left, final int right) {
        // bottom-up condition
        if (left == right) {
            return nums[left] == target ? left : -1;
        } else if (left > right) {
            // nums(left, right) is empty
            return -1;
        }

        // left < right
        // 0, 1 -> 0 + (1 - 0) / 2 = 0
        // 1, 2 -> 1 + (2 - 1) / 2 = 1
        // 1, 3 -> 1 + (3 - 1) / 2 = 2
        // 1, 4 -> 1 + (4 - 1) / 2 = 2
        final int middle = left + (right - left) / 2;

        final int leftResult = doSearch(nums, target, left, middle);
        if (leftResult != -1) {
            return leftResult;
        } else {
            return doSearch(nums, target, middle + 1, right);
        }
    }

}
