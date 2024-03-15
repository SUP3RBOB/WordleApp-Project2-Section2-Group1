#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define VALID_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"
#define KEY_BACKSPACE 8
#define KEY_ENTER 13

char word[] = "LIVER";

bool GetInputs(GameBoard* gameBoard) {
	if (gameBoard == NULL) {
		fprintf(stderr, "Unable to get keyboard input, game board doesn't exist\n");
		return false;
	}

	int keyInput = _getch();
	keyInput = toupper(keyInput);

	if (keyInput == KEY_ENTER && gameBoard->currentColumn >= BOARD_WIDTH) {
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

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			if (i < gameBoard->currentRow) {
				switch (GetLetterCase(gameBoard->grid[j][i])) {
					case NotInWord: printf("%c", gameBoard->grid[j][i]); break;
					case IsInWord: printf("%c", gameBoard->grid[j][i]); break;
					case IsInPosition: printf("%c", gameBoard->grid[j][i]); break;
				}
			} else {
				printf("%c", gameBoard->grid[j][i]);
			}
		}
		printf("\n");
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

LetterCase GetLetterCase(char letter) {
	for (int i = 0; i < strlen(word); i++) {
		if (letter == word[i]) {
			return IsInPosition;
		} else if (IsLetterInWord(letter)) {
			return IsInWord;
		} else {
			return NotInWord;
		}
	}
}
