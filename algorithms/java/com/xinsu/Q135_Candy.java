package com.xinsu;

/**
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
 *
 * 你需要按照以下要求，给这些孩子分发糖果：
 *
 * 每个孩子至少分配到 1 个糖果。
 * 相邻两个孩子中，评分更高的那个会获得更多的糖果。
 * 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：ratings = [1,0,2]
 * 输出：5
 * 解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
 * 示例 2：
 *
 * 输入：ratings = [1,2,2]
 * 输出：4
 * 解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
 *      第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
 *
 *
 * 提示：
 *
 * n == ratings.length
 * 1 <= n <= 2 * 104
 * 0 <= ratings[i] <= 2 * 104
 */
public class Q135_Candy {

    public int candy(int[] ratings) {
        // boundary case
        if (ratings.length == 0) {
            return 0;
        }

        final int[] left = new int[ratings.length];
        for (int i = 0; i < ratings.length; i++) {
            if (i > 0 && ratings[i - 1] < ratings[i]) {
                left[i] = left[i - 1] + 1;
            } else { // i == 0 || ratings[i - 1] >= ratings[i]
                left[i] = 1;
            }
        }

        int result = 0;

        int right_1 = 0; // the i-1-th right value
        int right = 0; // the i-th right value
        for (int i = ratings.length - 1; i > -1; i--) {
            // calculate the i-th right value
            if (i < ratings.length - 1 && ratings[i] > ratings[i + 1]) {
                right = right_1 + 1;
            } else {
                right = 1;
            }

            result += Math.max(left[i], right);

            // update the i-1-th right value for next loop
            right_1 = right;
        }

        return result;
    }

}
