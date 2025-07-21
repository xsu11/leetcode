package com.xinsu;

import java.util.Arrays;
import java.util.Comparator;

/**
 * We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of
 * profit[i].
 *
 * You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no
 * two jobs in the subset with overlapping time range.
 *
 * If you choose a job that ends at time X you will be able to start another job that starts at time X.
 *
 *
 *
 * Example 1:
 *
 *
 *
 * Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
 * Output: 120
 * Explanation: The subset chosen is the first and fourth job.
 * Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
 * Example 2:
 *
 *
 *
 * Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
 * Output: 150
 * Explanation: The subset chosen is the first, fourth and fifth job.
 * Profit obtained 150 = 20 + 70 + 60.
 * Example 3:
 *
 *
 *
 * Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
 * Output: 6
 *
 *
 * Constraints:
 *
 * 1 <= startTime.length == endTime.length == profit.length <= 5 * 104
 * 1 <= startTime[i] < endTime[i] <= 109
 * 1 <= profit[i] <= 104
 */

public class Q1235_MaximumProfitInJobScheduling {

    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        // sort by endTime
        final int[][] jobs = sortJob(startTime, endTime, profit);

        /*
         * f(i) represents the max profit after processing the i-th job, 1-based index
         *
         * Max profit comes from:
         * 1. Either don't do the i-th job, the profit is directly from f(i - 1),
         * 2. or do the i-th job, then the profit comes from jobs[i].profit + f(k), where k represents the LAST job that
         * endTime <= the i-th job's startTime
         *
         * f(i) = max(f(i-1), f(k) + jobs[i].profit), i > 0
         * f(0) = 0, i = 0
         *
         * f is an 1-based index array that represents f(i), while "jobs" in the following code is 0-based index array
         */
        final int[] f = new int[jobs.length + 1];
        f[0] = 0; // represents f(0) = 0
        for (int i = 1; i < f.length; i++) { // i is the index of f
            // k is the index of jobs, k might be -1 when no job founds, in which case f[k + 1] is f[0]
            final int k = searchJob(jobs, 0, i - 1, jobs[i - 1][0]);

            f[i] = Math.max(f[i - 1], f[k + 1] + jobs[i - 1][2]);
        }

        return f[f.length - 1];
    }

    private int[][] sortJob(int[] startTime, int[] endTime, int[] profit) {
        final int[][] jobs = new int[startTime.length][];
        for (int i = 0; i < startTime.length; i++) {
            jobs[i] = new int[] { startTime[i], endTime[i], profit[i] };
        }

        Arrays.sort(jobs, Comparator.comparingInt(a -> a[1]));

        return jobs;
    }

    private int searchJob(int[][] jobs, int left, int right, int targetStartTime) {
        // use binary search, find the LAST job that has endTime<=targetStartTime

        while (left < right) {
            final int mid = left + (right - left) / 2;
            if (jobs[mid][1] > targetStartTime) {
                right = mid;
            } else { // jobs[mid][1] <= targetStartTime
                left = mid + 1;
            }
        }

        /*
         * left == right, and jobs[left][1] >= targetStartTime
         * if jobs[left][1] == targetStartTime, then left must be the LAST job that has endTime<=targetStartTime
         * else if jobs[left][1] > targetStartTime, then left-1 would be the LAST job that has endTime<=targetStartTime
         *
         * returned index of jobs might be -1, which means no jobs found
         */
        return jobs[left][1] == targetStartTime ? left : left - 1;
    }

}
