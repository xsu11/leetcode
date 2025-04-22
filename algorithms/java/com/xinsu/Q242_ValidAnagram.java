package com.xinsu;

import java.util.HashMap;
import java.util.Map;

/*
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
        final Map<Character, Integer> solved = solve(s);
        return check(solved, t);
    }

    private Map<Character, Integer> solve(String s) {
        final Map<Character, Integer> solved = new HashMap<>();
        char[] ss = s.toCharArray();
        for (final char c : ss) {
            solved.put(c, solved.containsKey(c) ? solved.get(c) + 1 : 1);
        }

        return solved;
    }

    private boolean check(Map<Character, Integer> solved, String t) {
        final char[] tt = t.toCharArray();
        for (final char c : tt) {
            if (!solved.containsKey(c)) {
                return false;
            } else {
                final int count = solved.get(c);

                if (count < 1) {
                    return false;
                } else if (count == 1) {
                    solved.remove(c);
                } else {
                    solved.put(c, count - 1);
                }
            }
        }

        return solved.isEmpty();
    }

}
