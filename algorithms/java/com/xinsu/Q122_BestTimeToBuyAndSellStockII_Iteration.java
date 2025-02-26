package com.xinsu;

public class Q122_BestTimeToBuyAndSellStockII_Iteration {

    public int maxProfit(int[] prices) {
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                // can make profit
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }

}
