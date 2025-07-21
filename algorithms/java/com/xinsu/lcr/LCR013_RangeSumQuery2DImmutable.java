package com.xinsu.lcr;

/**
 * 给定一个二维矩阵 matrix，以下类型的多个请求：
 *
 * 计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。
 * 实现 NumMatrix 类：
 *
 * NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
 * int sumRegion(int row1, int col1, int row2, int col2) 返回左上角 (row1, col1) 、右下角 (row2, col2) 的子矩阵的元素总和。
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入:
 * ["NumMatrix","sumRegion","sumRegion","sumRegion"]
 * [[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
 * 输出:
 * [null, 8, 11, 12]
 *
 * 解释:
 * NumMatrix numMatrix = new NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]]);
 * numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
 * numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
 * numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
 *
 *
 * 提示：
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * -105 <= matrix[i][j] <= 105
 * 0 <= row1 <= row2 < m
 * 0 <= col1 <= col2 < n
 * 最多调用 104 次 sumRegion 方法
 *
 *
 * 注意：本题与主站 304 题相同： https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
 */

public class LCR013_RangeSumQuery2DImmutable {

    /*
     * Expand one row and one col to avoid index out of bound when calculating using row-1 and col-1:
     *
     * 1. sums[0][col] and sums[row][0] are all 0
     * 2. sums[row + 1][col + 1] is the sum of the matrix from (0,0) to (row,col)
     */
    private final int[][] sums;

    public LCR013_RangeSumQuery2DImmutable(int[][] matrix) {
        // boundary case
        if (matrix.length == 0 || matrix[0].length == 0) {
            sums = new int[0][0];
        } else {
            this.sums = new int[matrix.length + 1][matrix[0].length + 1];

            for (int r = 0; r < matrix.length; r++) {
                int rowSum = 0;
                for (int c = 0; c < matrix[0].length; c++) {
                    rowSum += matrix[r][c];
                    sums[r + 1][c + 1] = sums[r][c + 1] + rowSum;
                }
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row1][col2 + 1] - sums[row2 + 1][col1] + sums[row1][col1];
    }

}
