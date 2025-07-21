package com.xinsu.util;

import java.util.Random;

public class Sort {

    public void quickSort(final int[] nums, final int begin, final int end) {
        // bottom-up condition
        if (begin >= end) {
            return;
        }

        final int pivot = partition(nums, begin, end);
        quickSort(nums, begin, pivot);
        quickSort(nums, pivot + 1, end);
    }

    private int partition(final int[] nums, final int begin, final int end) {
        final int randomIndex = begin + new Random().nextInt(end - begin + 1);
        swap(nums, randomIndex, end); // swap pivot with the end ele

        int small = begin - 1; // small is the index of the last ele that is smaller than pivot
        for (int i = begin; i < end; i++) {
            if (nums[i] < nums[end]) {
                swap(nums, ++small, i);
            }
        }
        // all eles in [begin, small] are smaller than pivot, all eles in [small+1, end - 1] are larger than pivot

        // swap pivot from end back to small+1
        swap(nums, small + 1, end);
        return small + 1;
    }

    private void swap(final int[] nums, final int i, final int j) {
        final int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

}
