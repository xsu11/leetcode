package com.xinsu;

/**
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

public class Q746_MinCostClimbingStairs_Iteration_Simplified {

    public int minCostClimbingStairs(int[] cost) {
        // boundary case
        if (cost.length == 0) {
            return 0;
        }

        if (cost.length == 1) {
            return cost[0];
        }

        // cost.length >= 2

        int i_2 = cost[0];
        int i_1 = cost[1];

        for (int i = 2; i < cost.length; i++) {
            // calculate i
            final int i_0 = Math.min(i_2, i_1) + cost[i];

            // update i_1 and I_2 for next loop
            i_2 = i_1;
            i_1 = i_0;
        }

        return Math.min(i_2, i_1);
    }

}
