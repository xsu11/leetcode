package com.xinsu;

/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water
 * it can trap after raining.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case,
 * 6 units of rain water (blue section) are being trapped.
 * Example 2:
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 * Constraints:
 *
 * n == height.length
 * 1 <= n <= 2 * 104
 * 0 <= height[i] <= 105
 */

public class Q42_TrappingRainWater {

    public int trap(int[] height) {
        // boundary case
        if (height.length == 0) {
            return 0;
        }

        int water = 0;

        // left/right cursor to traverse all heights
        int left = 0;
        int right = height.length - 1;

        // leftMax/rightMax maximum height of left/right boundary
        int leftMax = height[left];
        int rightMax = height[right];

        while (left < right) {
            // can only trap water from smaller side
            if (leftMax < rightMax) {
                // left step forward
                left++;

                // then compare left with current leftMax
                leftMax = Math.max(leftMax, height[left]);
                // this only calculate trapping water at this specific pos left
                // this may trap water if leftMax > height[left], or not if height[left] is new leftMax
                water += leftMax - height[left];
            } else {
                right--;

                rightMax = Math.max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }

        return water;
    }

}
