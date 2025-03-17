package com.xinsu;

public class Q123_BestTimeToBuyAndSellStockIII {

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
        //
        // maxProfit(k, i) = max(maxProfit(k, i-1), maxProfit(k-1, j-1) + p(i) - p(j))   (0<=j<=i-1)

        // in this problem, only two trades are allowed, therefore k = 2

        // create the 2-d array
        // use first dimension index from 0, that is for price on day i
        // but use second dimension index from 1, that is for trade k, index = 0 has value 0 representing an initial fake profit
        final int trade = 2;
        final int[][] maxProfit = new int[trade + 1][prices.length];

        for (int k = 1; k < trade + 1; k++) {
            for (int i = 1; i < prices.length; i++) {
                maxProfit[k][i] = Math.max(maxProfit[k][i - 1], maxProfitTradeOnDayI(prices, i, maxProfit, k));
            }
        }

        return maxProfit[trade][prices.length - 1];
    }

    private static int maxProfitTradeOnDayI(int[] prices, int i, int[][] maxProfit, int k) {
        int profitTradeOnDayI = Math.max(0, prices[i] - prices[0]); // init at j = 0
        for (int j = 1; j < i; j++) {
            profitTradeOnDayI = Math.max(profitTradeOnDayI, maxProfit[k - 1][j - 1] + prices[i] - prices[j]);
        }
        return profitTradeOnDayI;
    }

}
