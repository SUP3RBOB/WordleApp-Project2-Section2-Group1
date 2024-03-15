#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define VALID_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define KEY_BACKSPACE 8
#define KEY_ENTER 13

// ANSI color codes for console output
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char word[] = "WORLD";

bool GetInputs(GameBoard* gameBoard) {
	if (gameBoard == NULL) {
		fprintf(stderr, "Unable to get keyboard input, game board doesn't exist\n");
		return false;
	}

	int keyInput = _getch();
	keyInput = toupper(keyInput);

	if (keyInput == KEY_ENTER && gameBoard->currentColumn >= BOARD_WIDTH) {
		NextRow(gameBoard);
		RefreshBoard(gameBoard);
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
			}
			else {
				printf("| %c ", gameBoard->grid[j][i]);
			}
		}
		printf("|\n");

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

LetterCase GetLetterCase(char letter, int pos) {
	if (letter == word[pos]) {
		return IsInPosition;
	} else if (IsLetterInWord(letter)) {
		return IsInWord;
	} else {
		return NotInWord;
	}
}
