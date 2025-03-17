package com.xinsu;

import java.util.PriorityQueue;

public class Q3275_KthNearestObstacleQueries {

    public int[] resultsArray(int[][] queries, int k) {
        // boundary case
        if (k <= 0) {
            return null;
        }

        final int[] result = new int[queries.length];

        final PriorityQueue<Integer> maxK = new PriorityQueue<>((a, b) -> b - a);
        for (int i = 0; i < queries.length; i++) {
            maxK.offer(Math.abs(queries[i][0]) + Math.abs(queries[i][1]));

            // ensure minQ's size <= k
            if (maxK.size() > k) {
                maxK.poll();
            }

            result[i] = maxK.size() < k ? -1 : maxK.peek();
        }

        return result;
    }

}
