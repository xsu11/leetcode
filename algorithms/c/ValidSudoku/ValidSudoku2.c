/*
 * ValidSudoku2.c
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

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	// illegal input, return false;
	if (boardRowSize != 9 || boardColSize != 9) {
		return false;
	}

	bool rows[9][9] = { false };
	bool columns[9][9] = { false };
	bool blocks[9][9] = { false };

	int column = 0;
	int row = 0;
	for (column = 0; column < boardColSize; column++) {
		for (row = 0; row < boardRowSize; row++) {
			if (board[column][row] != '.') {
				// get the index that board[col][row] should be in the matrix
				int index = board[column][row] - '1';
				// get which block that board[col][row] is in the blocks matrix
				int block = column / 3 * 3 + row / 3;

				if (rows[row][index] == true || columns[column][index] == true
						|| blocks[block][index] == true) {
					return false;
				}

				rows[row][index] = true;
				columns[column][index] = true;
				blocks[block][index] = true;
			}
		}
	}

	return true;
}
