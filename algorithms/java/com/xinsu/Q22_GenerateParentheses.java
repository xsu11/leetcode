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

public class Q22_GenerateParentheses {

    public List<String> generateParenthesis(final int n) {
        final List<String> result = new ArrayList<>();
        generate(n, result, "", 0, 0);
        return result;
    }

    // parenthesis: an ongoing combination
    // leftUsed/rightUsed: USED count of open/close P, leftUsed is ALWAYS >= rightUsed
    private void generate(
            final int n,
            final List<String> result,
            final String parenthesis,
            final int leftUsed,
            final int rightUsed) {
        // bottom-up condition
        // all open and close parentheses are in place, a permutation is found, add to result
        if (leftUsed == n && rightUsed == n) {
            result.add(parenthesis);
            return;
        }

        // leftUsed is ALWAYS >= rightUsed
        if (leftUsed > rightUsed) {
            // next pos can be a leftUsed OR rightUsed

            // first append a leftUsed if possible
            if (leftUsed < n) { // rightUsed < leftUsed < n
                // there are still leftUsed unused, append a leftUsed
                generate(n, result, parenthesis + "(", leftUsed + 1, rightUsed);
                // after generation remove last
            }

            // there are still rightUsed unused, append a rightUsed
            generate(n, result, parenthesis + ")", leftUsed, rightUsed + 1);
            // after generation remove last
        } else {
            // leftUsed == rightUsed < n
            // in this case can only append leftUsed
            generate(n, result, parenthesis + "(", leftUsed + 1, rightUsed);
            // after generation remove last
        }
    }

}
