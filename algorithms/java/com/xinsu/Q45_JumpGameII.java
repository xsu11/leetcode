package com.xinsu;

/**
 * You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
 *
 * Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at
 * nums[i], you can jump to any nums[i + j] where:
 *
 * 0 <= j <= nums[i] and
 * i + j < n
 * Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach
 * nums[n - 1].
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to
 * the last index.
 * Example 2:
 *
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 *
 *
 * Constraints:
 *
 * 1 <= nums.length <= 104
 * 0 <= nums[i] <= 1000
 * It's guaranteed that you can reach nums[n - 1].
 */

/*
        0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15
        7   0   9   6   9   6   1   7   9   0   1   2   9   0   0   1
init:   n                           f                                           jumps=1
                                        n                       f               farthest=21,jumps=3
                                                                    n   f=21    return jumps=3
 */

public class Q45_JumpGameII {

    public int jump(final int[] nums) {
        if (nums == null || nums.length <= 1) {
            return 0;
        }

        // nums.length > 1

        // near: left bound of current range reachability
        // far: right bound of current range reachability, this might be greater than nums.length - 1
        int near = 0;
        int far = near + nums[near];

        int jumps = 1; // how many jumps

        // greedy: when then range can reach the end, the jumps are minimum, return
        while (far < nums.length - 1) {
            // every coming into this while means finding a new range moving forward,
            // need to make a jump from last range to this new range
            jumps++;

            // the farthest index that can be reached by two steps within this range [near, far]
            // this might be greater than nums.length - 1
            int farthest = getFarthest(nums, near, far);

            // step for next while loop

            // already finish calculating farthest from near to far, therefore set near to far + 1
            near = far + 1;
            // far is the farthest range that can be reached now
            far = farthest;
        }

        // there is always a solution to jump to the last of nums;
        return jumps;
    }

    private static int getFarthest(final int[] nums, final int near, final int far) {
        // init farthest to a value that is small enough, could be 0, or -1, here use near
        int farthest = near;

        // find the farthest index of two steps within range [near, far]
        for (int nextNear = near; nextNear <= far; nextNear++) {
            // nextNear: left bound of next range reachability
            // nextFar: right bound of next range reachability, this might be greater than nums.length - 1
            final int nextFar = nextNear + nums[nextNear];
            if (farthest < nextFar) {
                farthest = nextFar;
            }
        }
        return farthest;
    }

}
