package com.xinsu;

/*
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future
 * to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 *
 *
 *
 * Example 1:
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 * Example 2:
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit = 0.
 *
 *
 * Constraints:
 *
 * 1 <= prices.length <= 105
 * 0 <= prices[i] <= 104
 */

public class Q121_BestTimeToBuyAndSellStock {

    public int maxProfit(int[] prices) {
        int maxProfit = 0;

        // boundary case
        if (prices.length < 2) {
            return maxProfit;
        }

        int globalMinPrice = prices[0];

        for (int i = 1; i < prices.length; i++) {
            // globalMinPrice always represents a day before day i, that is a buy

            // if sell on day i, what profit can get
            int profit = prices[i] - globalMinPrice;

            // update max profit if possible
            if (maxProfit < profit) {
                maxProfit = profit;
            }

            // update globalMinPrice if day i's price is lower
            if (prices[i] < globalMinPrice) {
                globalMinPrice = prices[i];
            }
        }

        return maxProfit;
    }

    public int maxProfit2(int[] prices) {
        // boundary case
        if (prices.length == 0) {
            return 0;
        }

        int maxProfit = 0;

        int minPrice = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++) {
            // update min price if needed
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            // now minPrice is the min price of prices[0:i], may be prices[i]

            if (minPrice < prices[i]) {
                // can get profit, update maxProfit if needed
                int profit = prices[i] - minPrice;
                if (maxProfit < profit) {
                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }

}
