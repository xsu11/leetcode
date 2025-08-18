package com.xinsu;

public class Q5_LongestPalindromicSubstring {

    public String longestPalindrome(String s) {
        // boundary case
        if (s == null || s.isEmpty()) {
            return "";
        }

        int begin = 0;
        int end = -1;

        for (int i = 0; i < s.length(); i++) {
            int oddLen = expand(s, i, i);
            int evenLen = expand(s,i, i + 1);
            int len = Math.max(oddLen, evenLen);

            if (end - begin < len) {
                begin = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(begin, end + 1);
    }

    private int expand(String s, int left, int right) {
        while (-1 < left && right < s.length() && s.charAt(left) == s.charAt(right) ) {
            left--;
            right++;
        }

        return right - left - 1;
    }

}
