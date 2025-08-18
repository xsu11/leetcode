package com.xinsu;

/**
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 *
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
 *
 * 假设每一种面额的硬币有无限个。
 *
 * 题目数据保证结果符合 32 位带符号整数。
 *
 *
 *
 * 示例 1：
 *
 * 输入：amount = 5, coins = [1, 2, 5]
 * 输出：4
 * 解释：有四种方式可以凑成总金额：
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 示例 2：
 *
 * 输入：amount = 3, coins = [2]
 * 输出：0
 * 解释：只用面额 2 的硬币不能凑成总金额 3 。
 * 示例 3：
 *
 * 输入：amount = 10, coins = [10]
 * 输出：1
 *
 *
 * 提示：
 *
 * 1 <= coins.length <= 300
 * 1 <= coins[i] <= 5000
 * coins 中的所有值 互不相同
 * 0 <= amount <= 5000
 */

public class Q518_CoinChangeII {

    public int change(int amount, int[] coins) {
        // of the coins cannot create amount, return directly
        if (!contains(amount, coins)) {
            return 0;
        }

        // dp[i] is the count of the combination of using coins to make amount i
        // dp[0] = 1: no coins are chosen to make amount 0
        final int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (final int coin : coins) {
            for (int i = coin; i < amount + 1; i++) {
                dp[i] += dp[i - coin];
            }
            // dp[i] now is the final count
        }

        return dp[amount];
    }

    private static boolean contains(int amount, int[] coins) {
        final boolean[] contains = new boolean[amount + 1];
        contains[0] = true;

        for (final int coin : coins) {
            for (int i = coin; i < amount + 1; i++) {
                contains[i] |= contains[i - coin];
            }
        }

        return contains[amount];
    }

}
