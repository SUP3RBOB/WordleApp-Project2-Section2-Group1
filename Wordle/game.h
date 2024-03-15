#pragma once

#include "game_board.h"

typedef enum letterStatus {
	NotInWord,
	IsInWord,
	IsInPosition,
} LetterStatus;

typedef struct game {
	bool running;
	bool gameEnded;
	bool gameWon;
	char word[6];
} Game;

Game* CreateGame();

bool DestroyGame(Game* game);

bool GetInputs(Game* game, GameBoard* gameBoard);
bool ReplayGame(Game* game, GameBoard* gameBoard);
void RefreshBoard(GameBoard* gameBoard);
bool IsValidInput(char letter);
bool IsLetterInWord(char letter);
LetterStatus GetLetterCase(char letter, int pos);
bool WordFound(GameBoard* gameBoard);