package com.xinsu;

public class Q81_SearchInRotatedSortedArrayII {

    public boolean search(int[] nums, int target) {
        return doSearch(nums, target, 0, nums.length - 1);
    }

    private boolean doSearch(final int[] nums, final int target, final int left, final int right) {
        // bottom-up condition
        if (left == right) {
            return nums[left] == target;
        } else if (left > right) {
            // nums(left, right) is empty
            return false;
        }

        // left < right
        // 0, 1 -> 0 + (1 - 0) / 2 = 0
        // 1, 2 -> 1 + (2 - 1) / 2 = 1
        // 1, 3 -> 1 + (3 - 1) / 2 = 2
        // 1, 4 -> 1 + (4 - 1) / 2 = 2
        final int middle = left + (right - left) / 2;
        return doSearch(nums, target, left, middle) || doSearch(nums, target, middle + 1, right);
    }

}
