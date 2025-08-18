package com.xinsu;

/**
 * 给你两个长度相同的字符串 s 和 t ，以及两个整数数组 nextCost 和 previousCost 。
 *
 * 一次操作中，你可以选择 s 中的一个下标 i ，执行以下操作 之一 ：
 *
 * 将 s[i] 切换为字母表中的下一个字母，如果 s[i] == 'z' ，切换后得到 'a' 。操作的代价为 nextCost[j] ，其中 j 表示 s[i] 在字母表中的下标。
 * 将 s[i] 切换为字母表中的上一个字母，如果 s[i] == 'a' ，切换后得到 'z' 。操作的代价为 previousCost[j] ，其中 j 是 s[i] 在字母表中的下标。
 * 切换距离 指的是将字符串 s 变为字符串 t 的 最少 操作代价总和。
 *
 * 请你返回从 s 到 t 的 切换距离 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "abab", t = "baba", nextCost = [100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0], previousCost = [1,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
 *
 * 输出：2
 *
 * 解释：
 *
 * 选择下标 i = 0 并将 s[0] 向前切换 25 次，总代价为 1 。
 * 选择下标 i = 1 并将 s[1] 向后切换 25 次，总代价为 0 。
 * 选择下标 i = 2 并将 s[2] 向前切换 25 次，总代价为 1 。
 * 选择下标 i = 3 并将 s[3] 向后切换 25 次，总代价为 0 。
 * 示例 2：
 *
 * 输入：s = "leet", t = "code", nextCost = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], previousCost = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
 *
 * 输出：31
 *
 * 解释：
 *
 * 选择下标 i = 0 并将 s[0] 向前切换 9 次，总代价为 9 。
 * 选择下标 i = 1 并将 s[1] 向后切换 10 次，总代价为 10 。
 * 选择下标 i = 2 并将 s[2] 向前切换 1 次，总代价为 1 。
 * 选择下标 i = 3 并将 s[3] 向后切换 11 次，总代价为 11 。
 *
 *
 * 提示：
 *
 * 1 <= s.length == t.length <= 105
 * s 和 t 都只包含小写英文字母。
 * nextCost.length == previousCost.length == 26
 * 0 <= nextCost[i], previousCost[i] <= 109
 */

public class Q3361_ShiftDistanceBetweenTwoStrings {

    public long shiftDistance(String s, String t, int[] nextCost, int[] previousCost) {
        final long[] nextSum = new long[26 * 2 + 1];
        final long[] previousSum = new long[26 * 2 + 1];
        for (int i = 1; i < 26 * 2; i++) {
            nextSum[i] = nextSum[i - 1] + nextCost[(i - 1) % 26];
            previousSum[i] = previousSum[i - 1] + previousCost[(i - 1) % 26];
        }

        long result = 0;
        for (int i = 0; i < s.length(); i++) {
            int sc = s.charAt(i) - 'a';
            int tc = t.charAt(i) - 'a';

            final int nextIndex;
            final int previousIndex;
            if (sc > tc) {
                // 0 1 ... tc1 ... sc ... 25 | 26 27 ... tc2 ... 52
                nextIndex = tc + 26; // nextSum[tc2] - nextSum[sc]
                previousIndex = sc; // prevSum[sc]
            } else if (sc < tc) {
                // 0 1 ... sc ... tc1 ... 25 | 26 27 ... tc2 ... 52
                nextIndex = tc;
                previousIndex = sc + 26;
            } else { // sc == tc
                // no need to shift
                continue;
            }

            result += Math.min(
                    nextSum[nextIndex] - nextSum[sc],
                    previousSum[previousIndex + 1] - previousSum[tc + 1]);
        }

        return result;
    }

}
