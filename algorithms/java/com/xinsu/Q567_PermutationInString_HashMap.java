package com.xinsu;

import java.util.HashMap;
import java.util.Map;

/**
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of s2.
 *
 *
 *
 * Example 1:
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * Example 2:
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 * Constraints:
 *
 * 1 <= s1.length, s2.length <= 104
 * s1 and s2 consist of lowercase English letters.
 */

public class Q567_PermutationInString_HashMap {

    public boolean checkInclusion(String s1, String s2) {
        // boundary case
        if (s1 == null || s1.isEmpty()
                || s2 == null || s2.isEmpty()
                || s1.length() > s2.length()) {
            return false;
        }

        // char -> count
        final Map<Character, Integer> counts = solve(s1);
        return check(s1, s2, counts);
    }

    private Map<Character, Integer> solve(final String s1) {
        final Map<Character, Integer> counts = new HashMap<>();
        for (final char c : s1.toCharArray()) {
            counts.putIfAbsent(c, 0);
            counts.put(c, counts.get(c) + 1);
        }

        return counts;
    }

    private boolean check(final String s1, final String s2, final Map<Character, Integer> counts) {
        // check first s1's length chars from s2's beginning
        final char[] c2 = s2.toCharArray();
        for (int i = 0; i < s1.length(); i++) {
            counts.computeIfPresent(c2[i], (ig, count) -> count - 1);
        }

        if (allZeros(counts)) {
            return true;
        }

        // then check remaining s1's length chars using slide window
        // use two pointers
        for (int begin = 1, end = s1.length(); end < c2.length; begin++, end++) {
            // compared to init or last loop, remove c2[begin - 1], add c2[end]
            counts.computeIfPresent(c2[begin - 1], (ig, count) -> count + 1);
            counts.computeIfPresent(c2[end], (ig, count) -> count - 1);
            if (allZeros(counts)) {
                return true;
            }
        }

        return false;
    }

    private boolean allZeros(final Map<Character, Integer> counts) {
        for (final Integer count : counts.values()) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }

}
