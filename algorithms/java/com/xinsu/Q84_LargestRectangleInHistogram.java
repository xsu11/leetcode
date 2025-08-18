package com.xinsu;

import java.util.Deque;
import java.util.LinkedList;

/**
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 *
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入：heights = [2,1,5,6,2,3]
 * 输出：10
 * 解释：最大的矩形为图中红色区域，面积为 10
 * 示例 2：
 *
 *
 *
 * 输入： heights = [2,4]
 * 输出： 4
 *
 *
 * 提示：
 *
 * 1 <= heights.length <=105
 * 0 <= heights[i] <= 104
 */

public class Q84_LargestRectangleInHistogram {

    public int largestRectangleArea(int[] heights) {
        // monotonic increasing stack, each e in stack is smaller than es on top of it
        // e in the stack is the index of heights
        final Deque<Integer> stack = new LinkedList<>();
        // push a dummy at the bottom of the stack, indicating the index -1
        stack.push(-1);

        int maxArea = 0;

        for (int i = 0; i < heights.length; i++) {
            // check stack.size() > 1 instead of !stack.isEmpty() because stack has a dummy at bottom
            while (stack.size() > 1 && heights[i] <= heights[stack.peek()]) {
                // found the closest e that is smaller than top, use it as right bound (exclusive)
                final int prevIndex = stack.pop();
                final int leftBoundIndex = stack.peek(); // left bound is the e under prevIndex in stack
                final int rightBoundIndex = i - 1;
                final int area = (rightBoundIndex - leftBoundIndex) * heights[prevIndex];
                if (maxArea < area) {
                    maxArea = area;
                }
            }

            stack.push(i);
        }

        // there might be some e left in the stack,
        // pop them to calculate are using maximum index of heights as right bound
        while (stack.size() > 1) {
            final int i = stack.pop();
            // left bound is the e under i in stack, might be dummy -1, that is the left pos of the heights left edge
            final int leftBoundIndex = stack.peek();
            // right bound is the heights right edge as all es on the right side are larger
            final int rightBoundIndex = heights.length - 1;
            final int area = (rightBoundIndex - leftBoundIndex) * heights[i];
            if (maxArea < area) {
                maxArea = area;
            }
        }

        return maxArea;
    }

}
