/*
 * GenerateParentheses2.c
 *
 *  Created on: Oct 11, 2016
 *      Author: xinsu
 *
 * Dynamic programming (iteration), with O(n * returnSize) time and O(n^3 + n * returnSize) space.
 * The table has fixed space usage: O(n^3). The results array use O(n * returnSize) space.
 */

/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
 ]
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

struct D {
	int data;
	int repeat;
	short **count;
};

int nextRow(short **count, int row, int col) {
	while (row > -1 && count[row][col] == 0) {
		row--;
	}

	return row;
}

void fillColumns(int n, struct D ***d, char **results, int returnSize, int col,
		int i, int j) {

	// the while loop fills one diagnal line, which fill one column in results array
	while (j < i + 1) {
		int row = returnSize - 1;

		for (int p = 0; p < d[i][j]->repeat; p++) {
			if (j > 0) {
				for (int q = 0; q < d[i][j - 1]->data; q++) {
					row = nextRow(d[i][j]->count, row, 1);
					results[row][col] = ')';

					d[i][j - 1]->count[row][0] = d[i][j]->count[row][0];
					d[i][j - 1]->count[row][1] = d[i][j]->count[row][1] - 1;
					row--;
				}
				d[i][j - 1]->repeat++;
			}

			if (j < i) {
				for (int q = 0; q < d[i - 1][j]->data; q++) {
					row = nextRow(d[i][j]->count, row, 0);
					results[row][col] = '(';

					d[i - 1][j]->count[row][0] = d[i][j]->count[row][0] - 1;
					d[i - 1][j]->count[row][1] = d[i][j]->count[row][1];
					row--;
				}
				d[i - 1][j]->repeat++;
			}
		}

		i--;
		j++;
	}
}

char **generateParenthesis(int n, int *returnSize) {
	if (n < 1) {
		*returnSize = 0;
		return NULL;
	}

	int i = 0;
	int j = 0;
	int k = 0;

	// alloc memory to the dynamic table
	struct D ***d = (struct D ***) calloc(n + 1, sizeof(struct D **));
	for (i = 0; i < n + 1; i++) {
		d[i] = (struct D **) calloc(i + 1, sizeof(struct D*));

		for (j = 0; j < i + 1; j++) {
			d[i][j] = (struct D *) calloc(1, sizeof(struct D));
		}
	}

	// fill dtable so as to get the returnSize
	d[0][0]->data = 1;
	for (i = 1; i < n + 1; i++) {
		d[i][0]->data = 1;
		for (j = 1; j < i; j++) {
			d[i][j]->data = d[i][j - 1]->data + d[i - 1][j]->data;
		}
		d[i][i]->data = d[i][i - 1]->data;
	}

	*returnSize = d[n][n]->data;

	// alloc memory for count array in each cell of dtable
	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < i + 1; j++) {
			d[i][j]->count = (short **) calloc(*returnSize, sizeof(short *));
			for (k = 0; k < *returnSize; k++) {
				d[i][j]->count[k] = (short *) calloc(2, sizeof(short));
			}
		}
	}

	// init the last cell in dtable to prepare for filling results array in next step
	d[n][n]->repeat = 1;
	for (k = 0; k < *returnSize; k++) {
		d[n][n]->count[k][0] = (short) n;
		d[n][n]->count[k][1] = (short) n;
	}

	int length = n * 2;
	int col = length - 1;

	// alloc memory for results array of strings
	char **results = (char **) calloc(*returnSize, sizeof(char *));
	for (i = 0; i < *returnSize; i++) {
		results[i] = (char *) calloc(length + 1, sizeof(char));
	}

	// fill the results array
	// fill the lower half
	for (k = n; k > 0; k--) {
		i = n;
		j = k;
		fillColumns(n, d, results, *returnSize, col--, i, j);
	}

	// fill the higher half
	for (k = n; k > 0; k--) {
		j = 0;
		i = k;
		fillColumns(n, d, results, *returnSize, col--, i, j);
	}

	// free dtable and seps array
	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < i + 1; j++) {
			for (k = 0; k < *returnSize; k++) {
				free(d[i][j]->count[k]);
			}
			free(d[i][j]);
		}
		free(d[i]);
	}
	free(d);

	return results;
}

int main() {
	int returnSize = 0;

//	for (int i = 0; i < returnSize; i++) {
//		printf("%s\n", results[i]);
//	}

	for (int i = 10; i < 16; i++) {
		char **results = generateParenthesis(i, &returnSize);
		printf("i = %d, returnSize = %d\n", i, returnSize);
	}
	/*
	 i = 10, returnSize = 16796
	 i = 11, returnSize = 58786
	 i = 12, returnSize = 208012
	 i = 13, returnSize = 742900
	 i = 14, returnSize = 2674440
	 i = 15, returnSize = 9694845
	 */
}
