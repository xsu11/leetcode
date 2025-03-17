package com.xinsu;

import java.util.Arrays;

/*
 * You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
 *
 * You can either start from the step with index 0, or the step with index 1.
 *
 * Return the minimum cost to reach the top of the floor.
 *
 *
 *
 * Example 1:
 *
 * Input: cost = [10,15,20]
 * Output: 15
 * Explanation: You will start at index 1.
 * - Pay 15 and climb two steps to reach the top.
 * The total cost is 15.
 * Example 2:
 *
 * Input: cost = [1,100,1,1,1,100,1,1,100,1]
 * Output: 6
 * Explanation: You will start at index 0.
 * - Pay 1 and climb two steps to reach index 2.
 * - Pay 1 and climb two steps to reach index 4.
 * - Pay 1 and climb two steps to reach index 6.
 * - Pay 1 and climb one step to reach index 7.
 * - Pay 1 and climb two steps to reach index 9.
 * - Pay 1 and climb one step to reach the top.
 * The total cost is 6.
 *
 *
 * Constraints:
 *
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 */

public class Q746_MinCostClimbingStairs_Memoization {

    public int minCostClimbingStairs(int[] cost) {
        final int[] dp = new int[cost.length];
        Arrays.fill(dp, -1);
        return Math.min(f(cost, cost.length - 2, dp), f(cost, cost.length - 1, dp));
    }

    private int f(final int[] cost, final int i, final int[] dp) {
        // bottom-up condition
        if (i < 0) {
            return 0;
        }

        if (i < 2) {
            dp[i] = cost[i];
            return dp[i];
        }

        // i >= 2

        // if min cost of step i has been calculated return immediately
        if (dp[i] >= 0) {
            return dp[i];
        }

        // recursion to calculate min cost of step i and memoized to dp
        dp[i] = Math.min(f(cost, i - 2, dp), f(cost, i - 1, dp)) + cost[i];
        return dp[i];
    }

}
