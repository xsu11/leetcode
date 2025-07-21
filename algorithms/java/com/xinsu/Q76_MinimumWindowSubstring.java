package com.xinsu;

import java.util.HashMap;
import java.util.Map;

/**
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""。
 *
 *
 *
 * 注意：
 *
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 * 示例 1：
 *
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 * 示例 2：
 *
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 * 示例 3:
 *
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 */

public class Q76_MinimumWindowSubstring {

    public String minWindow(String s, String t) {
        final Map<Character, Integer> solved = solve(t);
        return check(s, solved);
    }

    private Map<Character, Integer> solve(String t) {
        final Map<Character, Integer> solved = new HashMap<>();
        for (final char c : t.toCharArray()) {
            solved.put(c, solved.getOrDefault(c, 0) + 1);
        }

        return solved;
    }

    private String check(String s, Map<Character, Integer> solved) {
        int minLeft = -1;
        int minRight = -1;
        int minLength = Integer.MAX_VALUE;

        // use two pointers
        final Map<Character, Integer> checked = new HashMap<>();

        // first move right to next char that appears in solved
        int right = moveToNextRight(s, 0, solved, checked);
        int left = right; // left stars from the same pos as right

        // invariant:
        // 1. left and right point to char that appears in solved
        // 2. checked contains all chars that appears in solved in [left, right]
        while (right < s.length()) {
            while (cover(checked, solved) && left <= right) {
                if (left == right) {
                    // minimum length of 1 is reached, there is no shorter substring, early terminate
                    return s.substring(left, right + 1);
                }

                // window contains all chars in solved, update minLeft/minRight if needed
                final int length = right - left + 1;
                if (length < minLength) {
                    minLeft = left;
                    minRight = right;
                    minLength = length;
                }

                // shrink left by moving left to next char that appears in solved
                left = moveToNextLeft(s, left + 1, right, solved, checked);
            }

            // window does not cover all chars in solved
            // expand window by moving right forward to next char that appears in solved
            right = moveToNextRight(s, right + 1, solved, checked);
        }

        return minLeft != -1 ? s.substring(minLeft, minRight + 1) : "";
    }

    private static int moveToNextRight(
            String s,
            int begin,
            Map<Character, Integer> solved,
            Map<Character, Integer> checked) {
        int current = begin;
        while (current < s.length() && !solved.containsKey(s.charAt(current))) {
            current++;
        }

        // current points to next char that appears in solved
        if (current < s.length()) {
            addRightChar(s.charAt(current), checked);
        }
        return current;
    }

    private static void addRightChar(char rightC, Map<Character, Integer> checked) {
        checked.put(rightC, checked.getOrDefault(rightC, 0) + 1);
    }

    private static int moveToNextLeft(
            String s,
            int begin,
            int end,
            Map<Character, Integer> solved,
            Map<Character, Integer> checked) {
        // remove current left char from checked,
        removeLeftChar(s.charAt(begin - 1), checked);

        int current = begin;
        while (current <= end && !solved.containsKey(s.charAt(current))) {
            current++;
        }

        return current;
    }

    private static void removeLeftChar(char leftC, Map<Character, Integer> checked) {
        checked.put(leftC, checked.get(leftC) - 1);
    }

    private boolean cover(Map<Character, Integer> checked, Map<Character, Integer> solved) {
        for (final Map.Entry<Character, Integer> entry : solved.entrySet()) {
            final Character c = entry.getKey();
            final Integer count = entry.getValue();
            if (checked.getOrDefault(c, 0) < count) {
                return false;
            }
        }

        return true;
    }

}
