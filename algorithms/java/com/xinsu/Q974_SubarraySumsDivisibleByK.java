package com.xinsu;

import java.util.HashMap;
import java.util.Map;

public class Q974_SubarraySumsDivisibleByK {

    public int subarraysDivByK(int[] nums, int k) {
        /**
         * sum[0:j] = sum[0:i-1] + sum[i:j]
         * sum[i:j] = sum[0:j] - sum[0:i-1]
         * if sum[i:j] can be divided by k, then sum[0:j] % k == sum[0:i-1] % k
         * if sum < 0, then sum % k < 0, need to convert the mode to k + mode
         *
         * example:
         * k = 4, sum[0:j] = 9, sum[0:i-1] = -7
         * 9 - (-7) = 16 can be divided by 4
         * 9 % 4 = 1,
         * -7 % 4 = -3 convert to 4 + (-3) = 1
         * therefore, 9 % 4 == 7 % 4 converted
         */
        // key is sum[0,i] mod k, value is count of sum[0,i]
        final Map<Integer, Integer> modKMap = new HashMap<>();
        modKMap.put(0, 1); // empty subarray mod k is 0

        int result = 0;
        int sum = 0;
        for (int num : nums) {
            // update sum to get sum[0, i]
            sum += num;

            int mod = sum % k;

            if (mod < 0) {
                mod += k;
            }

            // find count from modKMap and add to result
            final Integer sameModeCount = modKMap.getOrDefault(mod, 0);
            result += sameModeCount;

            // update modKMap:
            modKMap.put(mod, sameModeCount + 1);
        }

        return result;
    }

}
