package com.xinsu;

public class Q122_BestTimeToBuyAndSellStockII {

    public int maxProfit(int[] prices) {
        // boundary case
        if (prices.length < 2) {
            return 0;
        }

        // profit can only be got by buying and then selling in different days, with different prices
        // buy on day i - 1 then sell on day i, profit = p(i) - p(i - 1), obviously make profit only if p(i) > p(i - 1)
        // no need to buy and sell at the same day

        // maxProfit(i) = maxProfit(i - 1) + max(0, p(i) - p(i - 1))

        return getMaxProfit(prices, prices.length - 1);
    }

    private int getMaxProfit(int[] prices, int i) {
        // bottom-up condition
        if (i == 0) {
            return 0;
        }

        // i > 0
        return getMaxProfit(prices, i - 1) + Math.max(0, prices[i] - prices[i - 1]);
    }

}
