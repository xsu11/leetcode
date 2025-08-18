package com.xinsu;

import java.util.Arrays;
import java.util.Map;

/**
 * 给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。
 *
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 给定 n 和 k，返回第 k 个排列。
 *
 *
 *
 * 示例 1：
 *
 * 输入：n = 3, k = 3
 * 输出："213"
 * 示例 2：
 *
 * 输入：n = 4, k = 9
 * 输出："2314"
 * 示例 3：
 *
 * 输入：n = 3, k = 1
 * 输出："123"
 *
 *
 * 提示：
 *
 * 1 <= n <= 9
 * 1 <= k <= n!
 */

public class Q60_PermutationSequence {

    public String getPermutation(int n, int k) {
        // create factorial array
        final int[] factorials = createFactorialArray(n);
        final boolean[] used = new boolean[n + 1];
        Arrays.fill(used, false);

        final StringBuilder sb = new StringBuilder();
        getKthPermutation(0, n, k, factorials, used, sb);
        return sb.toString();
    }

    private int[] createFactorialArray(int n) {
        final int[] factorials = new int[n + 1];
        factorials[0] = 1;
        for (int i = 1; i < n + 1; i++) {
            factorials[i] = factorials[i - 1] * i;
        }

        return factorials;
    }

    /*
     * index starts from 0, meaning starting from no i are being used
     */
    private void getKthPermutation(int index, int n, int k, int[] factorials, boolean[] used, StringBuilder sb) {
        // bottom-up condition
        if (index == n) {
            return;
        }

        // perm count of all n without index, that is total n-1-index's perm count
        final int permCount = factorials[n - 1 - index];
        int remains = k;

        int i = 1;
        for (; i < n + 1; i++) {
            if (used[i]) {
                // skip used i
                continue;
            }

            if (permCount < remains) {
                // if perm count is not enough, no need to actually create perm
                // just subtract the count from remains and continue to next loop
                remains -= permCount;
            } else { // permCount >= remains
                // found i that has per count covers remains, need to break the loop and calculate the kth perm
                break;
            }
        }

        // calculate the kth perm
        sb.append(i);
        used[i] = true;
        getKthPermutation(index + 1, n, remains, factorials, used, sb);
    }

}
