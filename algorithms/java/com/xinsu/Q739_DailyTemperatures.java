package com.xinsu;

import java.util.Deque;
import java.util.LinkedList;

/**
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
 * 如果气温在这之后都不会升高，请在该位置用 0 来代替。
 *
 *
 *
 * 示例 1:
 *
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 示例 2:
 *
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 示例 3:
 *
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 *
 *
 * 提示：
 *
 * 1 <= temperatures.length <= 105
 * 30 <= temperatures[i] <= 100
 */
public class Q739_DailyTemperatures {

    public int[] dailyTemperatures(int[] temperatures) {
        final int[] answer = new int[temperatures.length];

        // monotonic decreasing stack, each e in stack is larger than es on top of it
        // e in stack is the index of temperatures
        final Deque<Integer> stack = new LinkedList<>();
        for (int i = 0; i < temperatures.length; i++) {
            while (!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]) {
                final int prevIndex = stack.pop();
                answer[prevIndex] = i - prevIndex;
            }

            // either stack is empty, or stack top > temp[i] which means temp[i] is not a higher temp than top

            stack.push(i);
        }

        return answer;
    }

}
