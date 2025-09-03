package com.xinsu;

import java.util.Arrays;

/**
 * 给定一个二维整数数组 items ，其中 items[i] = [pricei, weighti] 表示第 i 个物品的价格和重量。
 *
 * 还给定一个 正 整数容量 capacity 。
 *
 * 每个物品可以分成两个部分，比率为 part1 和 part2 ，其中 part1 + part2 == 1 。
 *
 * 第一个物品的重量是 weighti * part1 ，价格是 pricei * part1 。
 * 同样，第二个物品的重量是 weighti * part2 ，价格是 pricei * part2 。
 * 使用给定的物品，返回填满容量为 capacity 的背包所需的 最大总价格 。如果无法填满背包，则返回 -1 。
 * 与实际答案的差距在 10-5 以内的 实际答案 将被视为接受。
 *
 *
 *
 * 示例 1 ：
 *
 * 输入：items = [[50,1],[10,8]], capacity = 5
 * 输出：55.00000
 * 解释：
 * 我们将第二个物品分成两个部分，part1 = 0.5，part2 = 0.5。
 * 第一个物品的价格和重量分别为 5 和 4 。同样地，第二个物品的价格和重量也是 5 和 4 。
 * 经过操作后，数组 items 变为 [[50,1],[5,4],[5,4]] 。
 * 为了填满容量为 5 的背包，我们取价格为 50 的第一个元素和价格为 5 的第二个元素。
 * 可以证明，55.0 是我们可以达到的最大总价值。
 * 示例 2 ：
 *
 * 输入：items = [[100,30]], capacity = 50
 * 输出：-1.00000
 * 解释：无法用给定的物品装满背包。
 *
 *
 * 提示：
 *
 * 1 <= items.length <= 105
 * items[i].length == 2
 * 1 <= pricei, weighti <= 104
 * 1 <= capacity <= 109
 */
public class Q2548_MaximumPriceToFillABag {

    public double maxPrice(int[][] items, int capacity) {
        // boundary case
        if (items.length == 0 || capacity <= 0) {
            return -1;
        }

        Arrays.sort(items, (a, b) -> a[1] * b[0] - a[0] * b[1]);

        double maxPrice = 0.0;
        double remain = capacity;

        for (int i = 0; i < items.length & remain > 0; i++) {
            double price = items[i][0];
            double weight = items[i][1];

            if (weight < remain) {
                // add all weight to backpack
                maxPrice += price;
                remain -= weight;
            } else {
                // only add remain to backpack
                maxPrice += price * remain / weight;
                remain = 0;
            }
        }

        return remain == 0 ? maxPrice : -1;
    }

}
