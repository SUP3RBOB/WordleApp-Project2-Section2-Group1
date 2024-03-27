#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "mainmenu.h"
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

int main(int argc, char* argv[]) {
	srand(time(NULL));

	Player* player = CreatePlayer();
	Game* game = CreateGame();
	GameBoard* gameBoard = CreateGameBoard();

	MainMenu menu = { 0, true, false };

	bool saveLoaded = LoadPlayerData(player, argc > 1 ? argv[1] : "");
	if (saveLoaded) {
		PrintPlayerInfo(player);
	}

	while (menu.running) {
		menu.exitMenu = false;
		RefreshMenu(&menu);
		if (saveLoaded) {
			PrintPlayerInfo(player);
		}

		UpdateMenu(&menu);

		RefreshMenu(&menu);
		if (saveLoaded) {
			PrintPlayerInfo(player);
		}

		if (menu.exitMenu && !saveLoaded) {
			printf("Enter a username (max 3 characters): \n");
			char input[USERNAME_LENGTH];
			fgets(input, 4, stdin);
			setName(player, input);

			char fileName[8];
			sprintf(fileName, "%s.bin", player->username);
			saveLoaded = SavePlayerData(player, fileName);

			game->running = true;
			system("cls");
			RefreshBoard(gameBoard);
		}

		if (menu.exitMenu) {
			game->running = true;
			RefreshBoard(gameBoard);
			RandomizeWord(game);
		}

		
		while (game->running) {
			if (!game->gameEnded) {
				GetInputs(game, gameBoard, player);
			} else {
				ReplayGame(game, gameBoard);
			}
		}
	}

	if (strcmp(player->username, "") != 0) {
		char fileName[8];
		sprintf(fileName, "%s.bin", player->username);
		SavePlayerData(player, fileName);
	}

	DestroyGame(game);
	DestroyGameBoard(gameBoard);
	DestroyPlayer(player);

	system("cls");

	return 0;
}