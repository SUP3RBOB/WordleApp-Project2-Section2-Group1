#include <stdio.h>
#include "game.h"

int main() {
	GameBoard* gameBoard = CreateGameBoard();
	bool running = true;

	while (running) {
		GetInputs(gameBoard);
	}

	DestroyGameBoard(gameBoard);
	return 0;
}