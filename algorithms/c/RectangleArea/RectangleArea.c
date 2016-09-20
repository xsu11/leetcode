/*
 * RectangleArea.c
 *
 *  Created on: Sep 20, 2016
 *      Author: xinsu
 */

/*
 * Find the total area covered by two rectilinear rectangles in a 2D plane.
 *
 * Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 *
 * Rectangle Area
 * 				 Y
 *               ^
 *               |
 *               |      (C,D):(3,4)
 *           ---------------
 *           |   |         |
 *           |   |         |
 *           |   |         |                (G,H):(7,2)
 *           |   |---------|---------------------
 *           |   |         |                    |
 *           |   |O(0,0)   |                    |
 *      ----------------------------------------|------> X
 * (A,B):(-1,0)  |                              |
 *               |                              |
 *               --------------------------------
 *         (E,F):(0,-2)
 *
 * Assume that the total area is never beyond the maximum possible value of int.
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
 */

#include <stdio.h>

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int ABCD = (C - A) * (D - B);
	int EFGH = (G - E) * (H - F);

	int w = 0;
	int h = 0;

	if (E <= A && C <= G) {
		//E A C G
		w = C - A;
	} else if (A <= E && G <= C) {
		// A E G C
		w = G - E;
	} else if (A <= E && E < C && C <= G) {
		// A E C G
		w = C - E;
	} else if (E <= A && A < G && G <= C) {
		// E A G C
		w = G - A;
	}

	if (F <= B && D <= H) {
		// F B D H
		h = D - B;
	} else if (B <= F && H <= D) {
		// B F H D
		h = H - F;
	} else if (B <= F && F < D && D <= H) {
		// B F D H
		h = D - F;
	} else if (F <= B && B < H && H <= D) {
		// F B H D
		h = H - B;
	}

	return ABCD + EFGH - w * h;
}
