/*
 * ValidSudoku1.c
 *
 *  Created on: Sep 04, 2016
 *      Author: xinsu
 */

/*
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 (9 x 9 board)

 A partially filled sudoku which is valid.

 Note:
 A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

#include <stdio.h>
#include <stdbool.h>

bool isValidSet(char *s) {
	char validSet[] = "123456789";

	int i = 0;
	while (s[i] != '\0') {
		if (s[i] < '1' || s[i] > '9') {
			return false;
		}

		if (s[i] != '.') {
			int v = s[i] - '1';

			if (validSet[v] != '.') {
				validSet[v] = '.';
			} else {
				return false;
			}
		}

		i++;
	}
	return true;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	if (boardRowSize != 9 || boardColSize != 9) {
		return false;
	}

	char *s = (char *) calloc(boardRowSize + 1, sizeof(char));

	int i = 0;
	int j = 0;
	for (i = 0; i < boardRowSize; i++) {
		if (!isValidSet(board[i])) {
			return false;
		}

		j = 0;
		for (j = 0; j < boardColSize; j++) {
			s[j] = board[j][i];
		}
		s[j] = '\0';

		if (!isValidSet(s)) {
			return false;
		}
	}

	int k = 0;
	int l = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			int idx = 0;
			for (k = 0; k < 3; k++) {
				for (l = 0; l < 3; l++) {
					s[idx] = board[i * 3 + k][j * 3 + l];
					idx++;
				}
			}
			s[idx] = '\0';

			if (!isValidSet(s)) {
				return false;
			}
		}
	}

	free(s);

	return true;
}
