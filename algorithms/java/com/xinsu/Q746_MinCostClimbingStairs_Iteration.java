package com.xinsu;

public class Q746_MinCostClimbingStairs_Iteration {

    public int minCostClimbingStairs(int[] cost) {
        // boundary case
        if (cost.length < 2) {
            return cost[cost.length - 1];
        }

        // cost.length >= 2

        final int[] dp = new int[cost.length];
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < cost.length; i++) {
            dp[i] = Math.min(dp[i - 2], dp[i - 1]) + cost[i];
        }

        return Math.min(dp[cost.length - 2], dp[cost.length - 1]);
    }

}
