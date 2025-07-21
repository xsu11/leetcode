package com.xinsu;

import java.util.HashMap;
import java.util.Map;

/**
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "anagram", t = "nagaram"
 *
 * Output: true
 *
 * Example 2:
 *
 * Input: s = "rat", t = "car"
 *
 * Output: false
 *
 *
 *
 * Constraints:
 *
 * 1 <= s.length, t.length <= 5 * 104
 * s and t consist of lowercase English letters.
 */

public class Q242_ValidAnagram {

    public boolean isAnagram(String s, String t) {
        // boundary case
        if (s == null || t == null
                || s.isEmpty() || t.isEmpty()
                || s.length() != t.length()) {
            return false;
        }

        // s != null && t != null && s.length() == t.length()

        final Map<Character, Integer> solved = solve(s);
        return check(t, solved);
    }

    private Map<Character, Integer> solve(final String s) {
        final Map<Character, Integer> solved = new HashMap<>();
        for (final char c : s.toCharArray()) {
            solved.put(c, solved.getOrDefault(c, 0) + 1);
        }
        return solved;
    }

    private boolean check(final String t, final Map<Character, Integer> solved) {
        for (final char c : t.toCharArray()) {
            if (!solved.containsKey(c)) {
                return false;
            }

            final int count = solved.get(c);
            if (count > 1) {
                solved.put(c, count - 1);
            } else { // count == 1
                solved.remove(c);
            }
        }

        return solved.isEmpty();
    }

}
