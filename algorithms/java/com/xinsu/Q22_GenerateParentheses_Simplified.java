package com.xinsu;

import java.util.ArrayList;
import java.util.List;

/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 *
 *
 * Example 1:
 *
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 *
 * Input: n = 1
 * Output: ["()"]
 *
 *
 * Constraints:
 *
 * 1 <= n <= 8
 */

public class Q22_GenerateParentheses_Simplified {

    public List<String> generateParenthesis(final int n) {
        final List<String> result = new ArrayList<>();
        generate(n, result, "", 0, 0);
        return result;
    }

    // parenthesis: an ongoing combination
    // left/right: USED count of open/close P, left is ALWAYS >= right
    private void generate(
            final int n,
            final List<String> result,
            final String parenthesis,
            final int left,
            final int right) {
        // boundary case
        if (left < right) {
            throw new IllegalArgumentException("unexpected left: " + left + ", right: " + right);
        }

        // bottom-up condition
        // all open and close parentheses are in place, a permutation is found, add to result
        if (left == n && right == n) {
            result.add(parenthesis);
            return;
        }

        // right is ALWAYS <= left
        // right is ALWAYS < n
        // left is ALWAYS <= n
        // (left == n && right < n), or (left < n && right < n)

        // only three possible cases:
        // 1. right == left < n -> append left
        // 2. right < left < n -> append left, or right
        // 3. right < left == n -> append right

        // 1. right == left < n, or -> append left
        // 2. right < left < n -> append left, or right
        // since right is ALWAYS <= left, the first half of these two conditions can be omitted after combination
        if (left < n) {
            // there are still left unused, append a left
            generate(n, result, parenthesis + "(", left + 1, right);
            // after generation remove last
        }

        // 2. right < left < n -> append left, or right
        // 3. right < left == n -> append right
        // since left is ALWAYS <= n, the second half of these two conditions can be omitted after combination
        if (right < left) {
            // there are still right unused, append a right
            generate(n, result, parenthesis + ")", left, right + 1);
            // after generation remove last
        }
    }

}
