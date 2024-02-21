#pragma once
#include <stdbool.h>
#define BOARD_WIDTH 5
#define BOARD_HEIGHT 6

typedef struct gameBoard {
	char grid[BOARD_WIDTH][BOARD_HEIGHT];
	int currentRow;
	int currentColumn;
} GameBoard;

GameBoard* CreateGameBoard();
void SetCharacterAtCurrentPosition(GameBoard* gameBoard, char c);
char GetCharacterAtCurrentPosition(GameBoard* gameBoard);
bool NextRow(GameBoard* gameBoard);
bool GetInputs(GameBoard* gameBoard);
void RefreshBoard(GameBoard* gameBoard);
bool DestroyGameBoard(GameBoard* gameBoard);