package com.xinsu;

public class Q746_MinCostClimbingStairs_Iteration_Simplified {

    public int minCostClimbingStairs(int[] cost) {
        // boundary case
        if (cost.length < 2) {
            return cost[cost.length - 1];
        }

        // cost.length >= 2

        int i_2 = cost[0];
        int i_1 = cost[1];

        for (int i = 2; i < cost.length; i++) {
            // calculate i
            final int i_0 = Math.min(i_2, i_1) + cost[i];

            // reset i_1 and I_2
            i_2 = i_1;
            i_1 = i_0;
        }

        return Math.min(i_2, i_1);
    }

}
