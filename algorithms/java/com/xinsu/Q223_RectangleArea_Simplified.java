package com.xinsu;

public class Q223_RectangleArea_Simplified {

    public int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        final int areaA = (ax2 - ax1) * (ay2 - ay1);
        final int areaB = (bx2 - bx1) * (by2 - by1);

        if (ax1 >= bx2 || bx1 >= ax2 || ay1 >= by2 || by1 >= ay2) {
            return areaA + areaB;
        } else {
            final int intersectWidth = Math.min(ax2,bx2) - Math.max(ax1, bx1);
            final int intersectHeight = Math.min(ay2,by2) - Math.max(ay1, by1);
            return areaA + areaB - intersectWidth * intersectHeight;
        }
    }

}
