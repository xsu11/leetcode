package com.xinsu;

/*
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 *
 * Find the maximum profit you can achieve. You may complete at most two transactions.
 *
 * Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy
 * again).
 *
 *
 *
 * Example 1:
 *
 * Input: prices = [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 * Example 2:
 *
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the
 * same time. You must sell before buying again.
 * Example 3:
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 * Constraints:
 *
 * 1 <= prices.length <= 105
 * 0 <= prices[i] <= 105
 */

public class Q123_BestTimeToBuyAndSellStockIII_Iteration_Simplified1 {

    public int maxProfit(int[] prices) {
        // boundary case
        if (prices.length == 0) {
            return 0;
        }

        // max profit got on day i comes from:
        // 1. either don't trade, the profit is the same as day i-1: maxProfit(k, i-1)
        // 2. or sell the stock that purchased on day j, this k-th trade's profit is p[i] - p[j]   (0<=j<=i-1)
        // since the stock purchased on day j is held until day i, therefor max profit before day j is maxProfit(k - 1, j - 1)
        // so the max profit is maxProfit(k-1, j-1) + p[i] - p [j]

        // maxProfit(k, i) = max(maxProfit(k, i-1), maxProfit(k-1, j-1) + p(i) - p(j))   (0<=j<=i-1)
        // maxProfit(k, i) = max(maxProfit(k, i-1), p(i) - (p(j) - maxProfit(k-1, j-1)))   (0<=j<=i-1)

        // in this problem, only two trades are allowed, therefore k = 2

        // p(i) - (p(j) - maxProfit(k-1, j-1)) make this max means to make p(j) - maxProfit(k-1, j-1) minimum
        // the reason to convert from calculating maximum of maxProfit(k-1, j-1) + p(i) - p(j) to minimum of p(j) - maxProfit(k-1, j-1) is that
        // p(j) - maxProfit(k-1, j-1) has nothing to do with i, therefore can be simplified to use i to represent i and j at the same time
        // and calculate minimum of p(j) - maxProfit(k-1, j-1) and maxProfit[k][i] in the same loop

        // p(j) - maxProfit(k-1, j-1) DOES NOT have actual meaning in this stock purchasing context

        // create the 2-d array
        // use first dimension index from 0, that is for price on day i
        // but use second dimension index from 1, that is for trade k, index = 0 has value 0 representing an initial fake profit
        final int trade = 2;
        final int[][] maxProfit = new int[trade + 1][prices.length];
        final int[] min = new int[prices.length]; // min for p(j) - maxProfit(k-1, j-1)

        for (int k = 1; k < trade + 1; k++) {
            min[0] = prices[0] - maxProfit[0][0];
            for (int i = 1; i < prices.length; i++) {
                min[i] = Math.min(min[i - 1], prices[i] - maxProfit[k - 1][i - 1]);
                maxProfit[k][i] = Math.max(maxProfit[k][i - 1], prices[i] - min[i]);
            }
        }

        return maxProfit[trade][prices.length - 1];
    }

}
