#define _CRT_SECURE_NO_WARNINGS

#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define VALID_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define KEY_BACKSPACE 8
#define KEY_ENTER 13
#define KEY_YES 121
#define KEY_NO 110

// ANSI color codes for console output
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char word[] = "SPANK";

Game* CreateGame() {
	Game* game = malloc(sizeof(Game));
	if (game == NULL) {
		fprintf(stderr, "Not enough memory to create game");
		return NULL;
	}

	game->running = true;
	game->gameEnded = false;
	game->gameWon = false;
	game->totalWords = InitializeWordBank(game);

	strncpy(word, game->wordBank[rand() % game->totalWords], WORD_LENGTH);

	return game;
}

int InitializeWordBank(Game* game) {
	FILE* file = fopen("words.txt", "r");
	if (file == NULL) {
		fprintf(stderr, "Could not open words.txt\n");
		return 0;
	}

	int wordCount = 0;

	while (fgets(word, sizeof(word), file)) {
		word[strcspn(word, "\n")] = 0;

		if (strlen(word) == 0) {
			continue;
		}

		game->wordBank[wordCount] = _strdup(word);
		wordCount++;
	}

	fclose(file);

	return wordCount;
}

bool DestroyGame(Game* game) {
	if (game == NULL) {
		fprintf(stderr, "Unable to destroy NULL game");
		return false;
	}

	free(game);

	return true;
}

bool GetInputs(Game* game, GameBoard* gameBoard) {
	if (gameBoard == NULL) {
		fprintf(stderr, "Unable to get keyboard input, game board doesn't exist\n");
		return false;
	}

	int keyInput = _getch();
	keyInput = toupper(keyInput);

	if (keyInput == KEY_ENTER && gameBoard->currentColumn >= BOARD_WIDTH) {

		if (WordFound(gameBoard)) {
			game->gameEnded = true;
			game->gameWon = true;
		}

		NextRow(gameBoard);
		RefreshBoard(gameBoard);

		if (gameBoard->currentRow >= BOARD_HEIGHT) {
			game->gameEnded = true;
			game->gameWon = false;
		}

		return true;
	}

	if (keyInput == KEY_BACKSPACE) {
		if (gameBoard->currentColumn > 0) {
			gameBoard->currentColumn--;
		}

		SetCharacterAtCurrentPosition(gameBoard, ' ');

		RefreshBoard(gameBoard);
		return true;
	}

	if (gameBoard->currentColumn >= BOARD_WIDTH) {
		return true;
	}

	if (!IsValidInput(keyInput)) {
		return false;
	}

	SetCharacterAtCurrentPosition(gameBoard, (char)keyInput);
	RefreshBoard(gameBoard);
	gameBoard->currentColumn++;

	return true;
}

bool ReplayGame(Game* game, GameBoard* gameBoard) {
	if (game == NULL || gameBoard == NULL) {
		return false;
	}

	if (game->gameWon) {
		printf("You won!\n");
	} else {
		printf("You Lost!\n");
	}
	printf("Play again? [y/n]");

	int input = _getch();
	input = tolower(input);

	if (input == KEY_YES) {
		ResetBoard(gameBoard);
		game->gameEnded = false;
		game->gameWon = false;
		RefreshBoard(gameBoard);
		RandomizeWord(game);
	} else if (input == KEY_NO) {
		game->running = false;
	} else {
		RefreshBoard(gameBoard);
	}
	
	return true;
}

bool IsValidInput(char letter) {
	for (int i = 0; i < 27; i++) {
		if (letter == VALID_CHARS[i]) {
			return true;
		}
	}
	
	return false;
}

void RefreshBoard(GameBoard* gameBoard) {
	system("cls");

	printf("//////////\\\\\\\\\\\\\\\\\\\\\\\n");
	for (int i = 0; i < BOARD_HEIGHT; i++) {
		printf("|   |   |   |   |   |\n");

		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (i < gameBoard->currentRow) {
				switch (GetLetterCase(gameBoard->grid[j][i], j)) {
				case NotInWord: printf("| "ANSI_COLOR_RED "%c" ANSI_COLOR_RESET " ", gameBoard->grid[j][i]); break;
				case IsInWord: printf("| "ANSI_COLOR_YELLOW "%c" ANSI_COLOR_RESET " ", gameBoard->grid[j][i]); break;
				case IsInPosition: printf("| " ANSI_COLOR_GREEN "%c" ANSI_COLOR_RESET " ", gameBoard->grid[j][i]); break;
				}
			} else {
				printf("| %c ", gameBoard->grid[j][i]);
			}
		}
		printf("|");

		if (i == gameBoard->currentRow) {
			printf(" <-");
		}

		printf("\n");

		printf("|   |   |   |   |   |\n");
		if (i < 2) {
			printf("//////////\\\\\\\\\\\\\\\\\\\\\\\n");
		}
		else if (i == 2) {
			printf("|||||||||||||||||||||\n");
		}
		else if (i > 2) {
			printf("\\\\\\\\\\\\\\\\\\\\\\\//////////\n");
		}
	}
}

bool IsLetterInWord(char letter) {
	for (int i = 0; i < strlen(word); i++) {
		if (letter == word[i]) {
			return true;
		}
	}
	
	return false;
}

LetterStatus GetLetterCase(char letter, int pos) {
	if (letter == word[pos]) {
		return IsInPosition;
	} else if (IsLetterInWord(letter)) {
		return IsInWord;
	} else {
		return NotInWord;
	}
}

bool WordFound(GameBoard* gameBoard) {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		if (gameBoard->grid[i][gameBoard->currentRow] != word[i]) {
			return false;
		}
	}
	
	return true;
}

bool RandomizeWord(Game* game) {
	if (game == NULL) {
		return false;
	}

	strncpy(word, game->wordBank[game->totalWords], WORD_LENGTH);

	return true;
}
