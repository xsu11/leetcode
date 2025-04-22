package com.xinsu;

/*
 * Given the coordinates of two rectilinear rectangles in a 2D plane, return the total area covered by the two
 * rectangles.
 *
 * The first rectangle is defined by its bottom-left corner (ax1, ay1) and its top-right corner (ax2, ay2).
 *
 * The second rectangle is defined by its bottom-left corner (bx1, by1) and its top-right corner (bx2, by2).
 *
 *
 *
 * Example 1:
 *
 * Rectangle Area
 * Input: ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
 * Output: 45
 * Example 2:
 *
 * Input: ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
 * Output: 16
 *
 *
 * Constraints:
 *
 * -104 <= ax1 <= ax2 <= 104
 * -104 <= ay1 <= ay2 <= 104
 * -104 <= bx1 <= bx2 <= 104
 * -104 <= by1 <= by2 <= 104
 */

public class Q223_RectangleArea {

    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        final int areaA = (ax2 - ax1) * (ay2 - ay1);
        final int areaB = (bx2 - bx1) * (by2 - by1);

        if (ax1 >= bx2 || bx1 >= ax2 || ay1 >= by2 || by1 >= ay2) {
            return areaA + areaB;
        } else {
            final int intersectWidth;
            if (ax1 <= bx1 && bx1 <= ax2 && ax2 <= bx2) {
                intersectWidth = ax2 - bx1;
            } else if (bx1 <= ax1 && ax1 <= bx2 && bx2 <= ax2) {
                intersectWidth = bx2 - ax1;
            } else if (ax1 <= bx1 && bx1 <= bx2 && bx2 <= ax2) {
                intersectWidth = bx2 - bx1;
            } else { // bx1 <= ax1 <= ax2 <= bx2
                intersectWidth = ax2 - ax1;
            }

            final int intersectHeight;
            if (ay1 <= by1 && by1 <= ay2 && ay2 <= by2) {
                intersectHeight = ay2 - by1;
            } else if (by1 <= ay1 && ay1 <= by2 && by2 <= ay2) {
                intersectHeight = by2 - ay1;
            } else if (ay1 <= by1 && by1 <= by2 && by2 <= ay2) {
                intersectHeight = by2 - by1;
            } else { // by1 <= ay1 <= ay2 <= by2
                intersectHeight = ay2 - ay1;
            }

            return areaA + areaB - intersectWidth * intersectHeight;
        }
    }

}
