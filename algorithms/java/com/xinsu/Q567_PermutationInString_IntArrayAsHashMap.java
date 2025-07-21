package com.xinsu;

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

public class Q567_PermutationInString_IntArrayAsHashMap {

    public boolean checkInclusion(String s1, String s2) {
        // boundary case
        if (s1 == null || s1.isEmpty()
                || s2 == null || s2.isEmpty()
                || s1.length() > s2.length()) {
            return false;
        }

        final int[] counts = solve(s1);
        return check(counts, s1.length(), s2);
    }

    private int[] solve(final String s1) {
        final int[] counts = new int[26];
        for (final char c : s1.toCharArray()) {
            counts[alphaIndex(c)]++;
        }

        return counts;
    }

    private boolean check(final int[] counts, final int s1Length, final String s2) {
        final char[] c2 = s2.toCharArray();

        for (int i = 0; i < s1Length; i++) {
            counts[alphaIndex(c2[i])]--;
        }

        if (allZeros(counts)) {
            return true;
        }

        for (int begin = 1, end = s1Length; end < c2.length; begin++, end++) {
            counts[alphaIndex(c2[begin - 1])]++;
            counts[alphaIndex(c2[end])]--;
            if (allZeros(counts)) {
                return true;
            }
        }

        return false;
    }

    private boolean allZeros(final int[] counts) {
        for (final int count : counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }

    private static int alphaIndex(final char c) {
        return c - 'a';
    }

}
