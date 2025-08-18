package com.xinsu;

/**
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 示例 2：
 *
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 *
 *
 * 提示：
 *
 * 1 <= n <= 45
 */

public class Q70_ClimbingStairs {

    /**
     * f(i) = f(i-1) + f(i-2), i > 1
     * f(0) = 1
     * f(1) = 1
     */
    public int climbStairs(int n) {
        // boundary case
        if (n < 0) {
            return 0;
        }
        if (n == 0 || n == 1) {
            return 1;
        }

        int i_2 = 1;
        int i_1 = 1;

        int i_0 = i_2 + i_1;
        for (int i = 2; i < n + 1; i++) {
            i_0 = i_2 + i_1;

            // update i_2/i_1 for next loop
            i_2 = i_1;
            i_1 = i_0;
        }

        return i_0;
    }

}
