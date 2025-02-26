package com.xinsu;

/*
 * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the
 * signed 32-bit integer range [-231, 231 - 1], then return 0.
 *
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 *
 *
 *
 * Example 1:
 *
 * Input: x = 123
 * Output: 321
 * Example 2:
 *
 * Input: x = -123
 * Output: -321
 * Example 3:
 *
 * Input: x = 120
 * Output: 21
 *
 *
 * Constraints:
 *
 * -231 <= x <= 231 - 1
 */

public class Q7_ReverseInteger {

    public int reverse(int x) {
        int result = 0;

        final int maxBoundary = Integer.MAX_VALUE / 10;
        final int maxRemaining = Integer.MAX_VALUE % 10;

        final int minBoundary = Integer.MIN_VALUE / 10;
        final int minRemaining = Integer.MIN_VALUE % 10;

        while (x != 0) {
            // d represents x's highest digit
            final int d = x % 10;
            if (result > maxBoundary || (result == maxBoundary && d > maxRemaining)
                    || result < minBoundary || (result == minBoundary && d < minRemaining)) {
                // after appending d, result will get overflowed, upper or lower bound
                return 0;
            } else {
                // append d to result's lowest digit
                result = result * 10 + d;
            }

            // step forward
            x /= 10;
        }

        return result;
    }

}
