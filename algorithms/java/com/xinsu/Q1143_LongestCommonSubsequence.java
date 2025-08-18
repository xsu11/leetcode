package com.xinsu;

public class Q1143_LongestCommonSubsequence {

    /**
     * f(i, j): text1[0:i] and text2[0:j]'s longest common subsequence
     *
     * f(i, j) = f(i-1, j-1), text1[i] == text2[j]
     * f(i, j) = max(f(i, j-1), f(i-1, j)), text1[i] != text2[j]
     */
    public int longestCommonSubsequence(String text1, String text2) {
        // boundary case
        if (text1 == null || text1.isEmpty()
                || text2 == null || text2.isEmpty()) {
            return 0;
        }

        final int m = text1.length();
        final int n = text2.length();

        final int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i < m + 1; i++) {
            final char c1 = text1.charAt(i - 1);
            for (int j = 1; j < n + 1; j++) {
                final char c2 = text2.charAt(j - 1);
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[m][n];
    }

}
