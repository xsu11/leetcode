package com.xinsu;

public class Q5_LongestPalindromicSubstring_DP {

    public String longestPalindrome(String s) {
        // boundary case
        if (s == null) {
            return "";
        } else if (s.length() == 1) {
            return s;
        }

        return null;
    }

}
