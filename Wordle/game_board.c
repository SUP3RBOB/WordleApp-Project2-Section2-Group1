#include "game_board.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

GameBoard* CreateGameBoard() {
	GameBoard* board = malloc(sizeof(GameBoard));
	if (board == NULL) {
		fprintf(stderr, "Not enough memory to create game board\n");
		return NULL;
	}

	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			board->grid[i][j] = '0';
		}
	}

	board->currentRow = 0;
	board->currentColumn = 0;

	return board;
}

void SetCharacterAtCurrentPosition(GameBoard* gameBoard, char c) {
	int row = gameBoard->currentRow;
	int col = gameBoard->currentColumn;

	gameBoard->grid[col][row] = c;
}

char GetCharacterAtCurrentPosition(GameBoard* gameBoard) {
	int row = gameBoard->currentRow;
	int col = gameBoard->currentColumn;

	return gameBoard->grid[col][row];
}

bool NextRow(GameBoard* gameBoard) {
	if (gameBoard == NULL) {
		fprintf(stderr, "Cannot go to the next row, game board doesn't exist\n");
		return false;
	}

	gameBoard->currentRow++;
	gameBoard->currentColumn = 0;
	
	return true;
}

bool DestroyGameBoard(GameBoard* gameBoard) {
	if (gameBoard == NULL) {
		fprintf(stderr, "Unable to free game board, game board doesn't exist\n");
		return false;
	}

	free(gameBoard);

	return true;
}
