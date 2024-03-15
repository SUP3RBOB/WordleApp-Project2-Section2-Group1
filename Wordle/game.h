#pragma once

#include "game_board.h"

typedef enum letterCase {
	NotInWord,
	IsInWord,
	IsInPosition,
} LetterCase;

bool GetInputs(GameBoard* gameBoard);
void RefreshBoard(GameBoard* gameBoard);
bool IsValidInput(char letter);
bool IsLetterInWord(char letter);
LetterCase GetLetterCase(char letter);