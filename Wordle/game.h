#pragma once

#include "game_board.h"
#define WORD_LENGTH 6
#define WORD_BANK_COUNT 100

typedef enum letterStatus {
	NotInWord,
	IsInWord,
	IsInPosition,
} LetterStatus;

typedef struct game {
	bool running;
	bool gameEnded;
	bool gameWon;
	char word[WORD_LENGTH];
	char* wordBank[WORD_BANK_COUNT];
	int totalWords;
} Game;

Game* CreateGame();

int InitializeWordBank(Game* game);
bool DestroyGame(Game* game);

bool GetInputs(Game* game, GameBoard* gameBoard);
bool ReplayGame(Game* game, GameBoard* gameBoard);
void RefreshBoard(GameBoard* gameBoard);
bool IsValidInput(char letter);
bool IsLetterInWord(char letter);
LetterStatus GetLetterCase(char letter, int pos);
bool WordFound(GameBoard* gameBoard);
bool RandomizeWord(Game* game);