#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define KEY_BACKSPACE 8
#define KEY_ENTER 13

bool GetInputs(GameBoard* gameBoard) {
	if (gameBoard == NULL) {
		fprintf(stderr, "Unable to get keyboard input, game board doesn't exist\n");
		return false;
	}

	int keyInput = _getch();

	if (keyInput == KEY_ENTER) {
		NextRow(gameBoard);
		return true;
	}

	if (keyInput == KEY_BACKSPACE) {
		if (gameBoard->currentColumn > 0) {
			gameBoard->currentColumn--;
		}

		SetCharacterAtCurrentPosition(gameBoard, '0');

		RefreshBoard(gameBoard);
		return true;
	}

	if (gameBoard->currentColumn >= BOARD_WIDTH) {
		return true;
	}

	SetCharacterAtCurrentPosition(gameBoard, (char)keyInput);
	RefreshBoard(gameBoard);
	gameBoard->currentColumn++;

	return true;
}