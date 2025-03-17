package com.xinsu;

import java.util.Arrays;

public class Q123_BestTimeToBuyAndSellStockIII_SimplifiedII {

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

        // min for p(j) - maxProfit(k-1, j-1)
        // only use the second dimension count of min to use each min for the first dimension prices,
        final int[] min = new int[trade + 1];

        Arrays.fill(min, prices[0]);

        for (int i = 1; i < prices.length; i++) {
            for (int k = 1; k < trade + 1; k++) {
                // before setting: min[k] is min from last i - 1
                // after setting: min[k] is min for this i
                min[k] = Math.min(min[k], prices[i] - maxProfit[k - 1][i - 1]);
                maxProfit[k][i] = Math.max(maxProfit[k][i - 1], prices[i] - min[k]);
            }
        }

        return maxProfit[trade][prices.length - 1];
    }

}
