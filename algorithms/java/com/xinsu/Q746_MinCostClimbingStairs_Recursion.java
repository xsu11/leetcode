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

public class Q746_MinCostClimbingStairs_Recursion {

    public int minCostClimbingStairs(int[] cost) {
        /*
         * climbing to the top of stairs defined by cost is to stand on step "length" (length is the index of cost),
         * however, since step "length", or "top", is imaginary and over its boundary, the min cost of standing on top
         * of the stairs is: minCost(length) = min(f(i - 1), f(i - 2)) (without adding the cost of imaginary "top")
         */
        // bottom-up condition
        if (cost.length == 0) {
            // need to log exceptional case
            return 0;
        }

        // climbing to the top either climbing from length-1 step or from length-2 step, and no need to pay on the top
        return Math.min(f(cost, cost.length - 2), f(cost, cost.length - 1));
    }

    // either from the i-2 step or from the i-1 step, pay min cost and then to i step then pay cost[i] to step further
    // f(i) = min(f(i - 2), f(i - 1)) + cost[i]
    // f: minimum cost of standing on step "i"
    // i: the index of cost
    private int f(final int[] cost, final int i) {
        if (i < 2) {
            return cost[i];
        }

        // i >= 2

        // recursion
        return Math.min(f(cost, i - 2), f(cost, i - 1)) + cost[i];
    }

}
