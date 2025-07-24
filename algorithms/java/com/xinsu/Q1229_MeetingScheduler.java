package com.xinsu;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * 给定两个人的空闲时间表：slots1 和 slots2，以及会议的预计持续时间 duration，请你为他们安排 时间段最早 且合适的会议时间。
 *
 * 如果没有满足要求的会议时间，就请返回一个 空数组。
 *
 * 「空闲时间」的格式是 [start, end]，由开始时间 start 和结束时间 end 组成，表示从 start 开始，到 end 结束。
 *
 * 题目保证数据有效：同一个人的空闲时间不会出现交叠的情况，也就是说，对于同一个人的两个空闲时间 [start1, end1] 和 [start2, end2]，要么 start1 > end2，要么 start2 > end1。
 *
 *
 *
 * 示例 1：
 *
 * 输入：slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 8
 * 输出：[60,68]
 * 示例 2：
 *
 * 输入：slots1 = [[10,50],[60,120],[140,210]], slots2 = [[0,15],[60,70]], duration = 12
 * 输出：[]
 *
 *
 * 提示：
 *
 * 1 <= slots1.length, slots2.length <= 104
 * slots1[i].length, slots2[i].length == 2
 * slots1[i][0] < slots1[i][1]
 * slots2[i][0] < slots2[i][1]
 * 0 <= slots1[i][j], slots2[i][j] <= 109
 * 1 <= duration <= 106
 */

public class Q1229_MeetingScheduler {

    public List<Integer> minAvailableDuration(int[][] slots1, int[][] slots2, int duration) {
        Arrays.sort(slots1, Comparator.comparingInt(a -> a[0]));
        Arrays.sort(slots2, Comparator.comparingInt(a -> a[0]));

        int p1 = 0;
        int p2 = 0;

        while (p1 < slots1.length && p2 < slots2.length) {
            // find the common duration of two slots
            final int commonStart = Math.max(slots1[p1][0], slots2[p2][0]);
            final int commonEnd = Math.min(slots1[p1][1], slots2[p2][1]);

            if (duration <= commonEnd - commonStart) {
                // a valid duration is found, return
                return Arrays.asList(commonStart, commonStart + duration);
            } else {
                /*
                 * intersect does not cover the duration
                 * move forward to pointer of the slot that ends earlier as the other one that ends later might have
                 * intersection with next slot, if these two slots ends at the same time, move both forward to next slot
                 */
                if (slots1[p1][1] < slots2[p2][1]) {
                    p1++;
                } else if (slots1[p1][1] == slots2[p2][1]) {
                    p1++;
                    p2++;
                } else { // slots1[p1][1] > slots2[p2][1]
                    p2++;
                }
            }
        }

        // no valid intersection is found, return empty list
        return Collections.emptyList();
    }

}
