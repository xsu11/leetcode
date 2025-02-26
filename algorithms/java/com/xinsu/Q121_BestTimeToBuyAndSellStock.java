package com.xinsu;

public class Q121_BestTimeToBuyAndSellStock {

    public int maxProfit(int[] prices) {
        int result = 0;

        // boundary case
        if (prices.length < 2) {
            return result;
        }

        int min = prices[0];

        for (int i = 1; i < prices.length; i++) {
            // min always represents a day before day i, that is a buy

            // if sell on day i, what profit can get
            int currentProfit = prices[i] - min;

            if (currentProfit > result) {
                result = currentProfit;
            }

            // update min if day i's price is lower
            if (prices[i] < min) {
                min = prices[i];
            }
        }

        return result;
    }

}
