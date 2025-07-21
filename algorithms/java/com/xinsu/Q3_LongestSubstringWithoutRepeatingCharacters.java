package com.xinsu;

import java.util.HashMap;
import java.util.Map;

/*
 * Given a string s, find the length of the longest
 * substring
 *  without duplicate characters.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * Example 2:
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * Example 3:
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 *
 * Constraints:
 *
 * 0 <= s.length <= 5 * 104
 * s consists of English letters, digits, symbols and spaces.
 */

public class Q3_LongestSubstringWithoutRepeatingCharacters {

    public int lengthOfLongestSubstring(final String s) {
        // boundary case
        if (s == null || s.isEmpty()) {
            return 0;
        }

        // store the char -> pos map that has been visited
        final Map<Character, Integer> positions = new HashMap<>();

        int maxLength = 0;

        // use two pointers
        for (int left = 0, right = 0; right < s.length(); right++) {
            final char rightC = s.charAt(right);

            if (positions.containsKey(rightC)) {
                // rightC appeared before right, find the longest valid substring by resetting left
                final Integer rightPos = positions.get(rightC);
                if (left <= rightPos) {
                    // rightC appeared in [left, right), reset left to next pos of rightPos
                    left = rightPos + 1;
                }
            }

            // if rightC appears in the [left, right] window, already reset left to the pos next to the appearance of
            // rightC within window, else, [left, right] expands to a longer substring
            // now the new [left, right] is a newly found substring
            // calculate [left, right] length and compare
            final int length = right - left + 1;
            if (maxLength < length) {
                maxLength = length;
            }

            // rightC has been visited, now need to update/put pos for rightC
            positions.put(rightC, right);
        }

        return maxLength;
    }

}
