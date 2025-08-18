package com.xinsu;

/**
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle
 * 不是 haystack 的一部分，则返回  -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：haystack = "sadbutsad", needle = "sad"
 * 输出：0
 * 解释："sad" 在下标 0 和 6 处匹配。
 * 第一个匹配项的下标是 0 ，所以返回 0 。
 * 示例 2：
 *
 * 输入：haystack = "leetcode", needle = "leeto"
 * 输出：-1
 * 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 *
 *
 * 提示：
 *
 * 1 <= haystack.length, needle.length <= 104
 * haystack 和 needle 仅由小写英文字符组成
 */

public class Q28_FindTheIndexOfTheFirstOccurrenceInaString_Simplified2 {

    public int strStr(String haystack, String needle) {
        // boundary case
        if (haystack == null || haystack.isEmpty()
                || needle == null || needle.isEmpty()) {
            return 0;
        }

        final char[] s = haystack.toCharArray();
        final char[] p = needle.toCharArray();

        final int[] pi = solve(p);
        return check(s, p, pi);
    }

    /**
     * 对于长度为 m 的字符串 s，其前缀函数 pi(i)(0≤i<m) 表示 s 的子串 s[0:i] 的最长的相等的真前缀与真后缀的长度。
     * 特别地，如果不存在符合条件的前后缀，那么 pi(i)=0。其中真前缀与真后缀的定义为不等于自身的的前缀与后缀。
     *
     * s: a a b a a a b a a b
     *
     * pi(0)=0，因为 a 没有真前缀和真后缀，根据规定为 0（可以发现对于任意字符串 pi(0)=0 必定成立）
     * pi(1)=1，因为 aa 最长的一对相等的真前后缀为 a，长度为 1
     * pi(2)=0，因为 aab 没有对应真前缀和真后缀，根据规定为 0
     * pi(3)=1，因为 aaba 最长的一对相等的真前后缀为 a，长度为 1
     * pi(4)=2，因为 aabaa 最长的一对相等的真前后缀为 aa，长度为 2
     * pi(5)=2，因为 aabaaa 最长的一对相等的真前后缀为 aa，长度为 2
     * pi(6)=3，因为 aabaaab 最长的一对相等的真前后缀为 aab，长度为 3
     * pi(7)=4，因为 aabaaaba 最长的一对相等的真前后缀为 aab，长度为 4
     * pi(8)=5，因为 aabaaabaa 最长的一对相等的真前后缀为 aab，长度为 5
     * pi(9)=0，因为 aabaaabaab 最长的一对相等的真前后缀为 aab，长度为 0
     *
     * pi(i) = [0,1,0,1,2,2,3,4,5,0]
     */
    private int[] solve(char[] p) {
        final int[] pi = new int[p.length];
        // pi(0)=0，因为 a 没有真前缀和真后缀，根据规定为 0（可以发现对于任意字符串 pi(0)=0 必定成立）
        pi[0] = 0;

        // boundary case
        if (p.length == 1) {
            return pi;
        }

        // p.length > 1

        int lastMatchCount = 0;
        for (int i = 1; i < p.length; i++) {
            lastMatchCount = pi[i - 1];

            // since this while loop will change lastMatchCount, need to check lastMatchCount > 0 to enter the loop
            while (lastMatchCount > 0 && p[lastMatchCount] != p[i]) {
                /*
                 * s: a a b a a a b a a b
                 * pi(8)=5，因为 aabaaabaa 最长的一对相等的真前后缀为 aab，长度为 5。
                 * pi = [0,1,0,1,2,2,3,4,5]
                 * 下一次循环i=9
                 * aabaaabaa b
                 * lastMatch = pi[i-1] = pi[8] = 5
                 * aabaaabaa 中 前缀 aabaa 与后缀 aabaa 相同
                 * 测试 p[5](a) != p[9](b)
                 * 则接下来需要判断前缀aabaa的前缀 与后缀 aabaa中 的后缀最多有多少相同，也就是solved[4] = pi[lastMatch-1]
                 */
                lastMatchCount = pi[lastMatchCount - 1];
            }

            // set pi[i]
            // need to check p[i] with next char of the previous match part, that is p[matchCount]
            if (p[lastMatchCount] == p[i]) {
                pi[i] = lastMatchCount + 1;
            } // else pi[i] maintains the original value 0
        }

        return pi;
    }

    private int check(char[] s, char[] p, int[] pi) {
        int matchCount = 0;
        // check match count for s[0:s.length -1] with p
        for (int i = 0; i < s.length; i++) {
            // initially matchCount is 0
            // after last loop, matchCount is 0(no match) or >0(partial match), checkout both cases

            /*
             * partial match from last loop, need to check s[i] with the next char of the match part
             *
             * the index of the last char of the match part is matchCount - 1, so the index of the next char of the
             * match part is matchCount
             *
             * since this while loop will change matchCount, need to check matchCount > 0 to enter the loop
             */
            while (matchCount > 0 && p[matchCount] != s[i]) {
                matchCount = pi[matchCount - 1];
            }

            // matchCount == 0 || (matchCount > 0 && p[matchCount] == s[i])
            // now matchCount is the match count of how many chars matching of suffix of s[0:i-1] with p's prefix
            // that is, s[i-matchCount:i-1] matches p[0:matchCount-1]
            // so need to check s[i] with next char of the match part of p, that is p[matchCount]
            if (p[matchCount] == s[i]) {
                matchCount++;
            }

            // after update of matchCount, need to check whether we have found a match by checking matchCount
            if (matchCount == p.length) {
                /*
                 * the first occurrence is found, now i is the last char of the match string,
                 * need to return the first char's index
                 *
                 * s: xxxx abc xxx
                 * p: abc
                 * when matching, i is index of char c in s, i = 6, p.length = 3, the first char's index is 4
                 */
                return i - p.length + 1;
            }
        }

        // no match found
        return -1;
    }

}
