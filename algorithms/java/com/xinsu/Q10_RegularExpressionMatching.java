package com.xinsu;

/*
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
 *
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 *
 *
 *
 * Example 1:
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * Example 2:
 *
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
 * Example 3:
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Constraints:
 *
 * 1 <= s.length <= 20
 * 1 <= p.length <= 20
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
 */

public class Q10_RegularExpressionMatching {

    public boolean isMatch(String s, String p) {
        // boundary case
        if (s == null || p == null) {
            return false;
        }

        final int m = s.length();
        final int n = p.length();
        char[] ss = s.toCharArray();
        char[] pp = p.toCharArray();

        // create dp
        final boolean[][] dp = new boolean[m + 1][n + 1];
        dp[0][0] = true; // s = "", p = "" -> match

        // WARNING: i/j is index in dp, which is one more than the index in ss/pp
        for (int i = 0; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (pp[j - 1] == '*') {
                    if (match(ss, pp, i, j - 1)) {
                        // ...x y b        ...x y b
                        // ...a . *   ->   .. a
                        dp[i][j] = dp[i][j - 2]
                                // ...x y b        ...x y
                                // ...a b *   ->   ...a b *
                                || dp[i - 1][j];
                                // ...x y b        ...x y b        ...x y
                                // ...a b *   ->   ...a b     ->   ...a
                                // || dp[i][j - 1];
                    } else {
                        // ...x y z        ...x y z
                        // ...a b *   ->   ...a
                        dp[i][j] = dp[i][j - 2];
                    }
                } else if (match(ss, pp, i, j)) { // pp[j - 1] is '.' or a letter
                    // ...x y   z          ...x y
                    // ...a b [./z]   ->   ...a b
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // ...x y z
                // ...a b c   ->   false
            }
        }

        return dp[m][n];
    }

    // WARNING: i/j is index in dp, which is one more than the index in ss/pp
    private boolean match(final char[] ss, final char[] pp, final int i, final int j) {
        if (i == 0 || j == 0) {
            return false;
        }

        if (pp[j - 1] == '.') {
            return true;
        }

        return ss[i - 1] == pp[j - 1];
    }

}
