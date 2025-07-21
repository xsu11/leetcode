package com.xinsu;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

/**
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，
 * 并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。
 *
 *
 *
 * 示例 1：
 *
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 示例 2：
 *
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *
 * 提示：
 *
 * 1 <= intervals.length <= 104
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 104
 */
public class Q56_MergeIntervals {

    public int[][] merge(int[][] intervals) {
        // boundary case
        if (intervals.length == 0) {
            return new int[0][2];
        }

        // sort intervals by left
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));

        final List<int[]> merged = new ArrayList<>();
        for (final int[] interval : intervals) {
            final int left = interval[0];
            final int right = interval[1];

            if (merged.isEmpty() || merged.get(merged.size() - 1)[1] < left) {
                // left beyonds the rightmost of merged, add this interval into merged's end
                merged.add(new int[] { left, right });
            } else {
                // left is within the existing range mf merged
                final int[] maxInterval = merged.get(merged.size() - 1);
                if (maxInterval[1] < right) {
                    maxInterval[1] = right;
                }
            }
        }

        return merged.toArray(new int[merged.size()][]);
    }

}
