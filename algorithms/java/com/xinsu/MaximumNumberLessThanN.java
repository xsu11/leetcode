package com.xinsu;

import java.util.Arrays;

public class MaximumNumberLessThanN {

    public int maxNumber(int[] nums, int n) {
        // boundary case
        if (nums.length == 0 || n <= 0 || containsNegative(nums)) {
            return -1;
        }

        final StringBuilder resultSB = new StringBuilder();

        // sort to use b-search from array
        Arrays.sort(nums);

        final String maxBelowNs = String.valueOf(getMaxBelowNums(nums, n));
        // whether last chosen num from nums < maxBelowNums[i - 1]
        boolean lastChosenNumSmaller = false;
        for (int i = 0; i < maxBelowNs.length(); i++) {
            if (lastChosenNumSmaller) {
                // last chosen num from nums < maxBelowNums[i - 1]
                // just append max num from nums to the end
                resultSB.append(nums[nums.length - 1]);
            } else {
                // last chosen num from nums >= maxBelowNums[i - 1]
                final int chosenNumIndex = choseNum(nums, maxBelowNs, i);
                resultSB.append(nums[chosenNumIndex]);

                if (nums[chosenNumIndex] < charToInt(maxBelowNs, i)) {
                    lastChosenNumSmaller = true;
                }
            }
        }

        return Integer.getInteger(resultSB.toString());
    }

    private boolean containsNegative(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 0) {
                return true;
            }
        }

        return false;
    }

    private static int charToInt(String maxPossibleNs, int i) {
        return maxPossibleNs.charAt(i) - '0';
    }

    private int getMaxBelowNums(int[] nums, int n) {
        final String ns = String.valueOf(n);
        if (checkSameLength(ns, nums[0])) {
            // 0. n = 23121, nums = {1,4,9}, maxBelowNum = 23120
            // 1. n = 23121, nums = {2,4,9}, maxBelowNum = 23120
            return n - 1;
        } else {
            // 2. n = 23121, nums = {3,4,9}, maxBelowNum = 9999
            // 3. n = 21121, nums = {2,4,9}, maxBelowNum = 9999
            // 4. n = 22222, nums = {2,4,9}, maxBelowNum = 9999
            return (int) Math.pow(10, ns.length() - 1) - 1;
        }
    }

    private boolean checkSameLength(String ns, int minNum) {
        final int nStart = charToInt(ns, 0);
        if (nStart < minNum) {
            // 2. n = 23121, nums = {3,4,9}, maxBelowNum = 9999
            // nStart = 2, minNum = 3
            return false;
        } else if (nStart == minNum) {
            // 1. n = 23121, nums = {2,4,9}, maxBelowNum = 23120
            // 3. n = 21121, nums = {2,4,9}, maxBelowNum = 9999
            // 4. n = 22222, nums = {2,4,9}, maxBelowNum = 9999
            // nStart = 2, minNum = 2
            return checkSameLength(ns.substring(1), minNum);
        } else { // nStart > minNum
            // 0. n = 23121, nums = {1,4,9}, maxBelowNum = 23120
            // nStart = 2, minNum = 1
            return true;
        }
    }

    // n = 2411, nums = {2, 4, 6, 8}, maxBelowNum = 2410
    // i = 0, cur = 2, next = 4
    //      search cur=2, found nums[0] in nums, return searchIndex = 0
    // i = 1, cur = 4, next = 1
    //      search cur-1=3, not found in nums, searchIndex = 1, return searchIndex-1=0
    private int choseNum(int[] nums, String maxBelowNs, int i) {
        int cur = charToInt(maxBelowNs, i);

        if (i < maxBelowNs.length() - 1) {
            final int next = charToInt(maxBelowNs, i + 1);
            if (next < nums[0]) {
                // next in maxBelowNs < min of nums, cur cannot be obtained, try cur - 1
                cur--;
            }
        }

        final int searchIndex = binarySearch(nums, cur);

        // if not found:
        // either, cur > nums[nums.length - 1], searchIndex = nums.length
        // or, cur < nums[0], searchIndex = 0
        //      cur < nums[searchIndex]
        // or, nums[0] < cur < nums[nums.length - 1]
        //      nums[searchIndex - 1] < cur < nums[searchIndex]
        //
        // in these cases, need to return the index before searchIndex
        if (searchIndex == nums.length || (cur != nums[searchIndex] && cur < nums[searchIndex])) {
            return searchIndex - 1;
        } else {
            // found cur, just return the index
            return searchIndex;
        }
    }

    private int binarySearch(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                return mid;
            } else {
                right = mid - 1;
            }
        }

        // when not found:
        // return the supposed pos of target, therefore nums[left - 1] < target < nums[left]
        return left;
    }

}
