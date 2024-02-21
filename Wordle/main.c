#include <stdio.h>
#include "game_board.h"

int main() {
	GameBoard* gameBoard = CreateGameBoard();

	while (true) {
		GetInputs(gameBoard);
	}

	DestroyGameBoard(gameBoard);
	return 0;
}