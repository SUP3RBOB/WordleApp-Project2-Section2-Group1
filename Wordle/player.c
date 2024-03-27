#define _CRT_SECURE_NO_WARNINGS

#include "player.h"
#include <stdio.h>
#include <stdlib.h>

Player* CreatePlayer() {
	Player* player = malloc(sizeof(Player));
	if (player == NULL) {
		fprintf(stderr, "Not enough memory to create player");
		return NULL;
	}

	strncpy(player->username, "", USERNAME_LENGTH);
	player->gamesPlayed = 0;
	player->totalWins = 0;
	player->totalLosses = 0;
	player->winStreak = 0;
	player->highestWinStreak = 0;

	return player;
}

bool SavePlayerData(Player* player, char fileName[]) {
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		fprintf(stderr, "Unable to open file %s for saving", fileName);
		return false;
	}

	fwrite(player, sizeof(Player), 1, fp);

	return true;
}

bool LoadPlayerData(Player* player, char fileName[]) {
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		return false;
	}

	fread(player, sizeof(Player), 1, fp);

	return true;
}

void PrintPlayerInfo(Player* player) {
	printf("Welcome Back %s!\n\n", player->username);
	printf("Current Win Streak: %d\n", player->winStreak);
	printf("Highest Win Streak: %d\n", player->highestWinStreak);
	printf("Games Played: %d\n", player->gamesPlayed);
	printf("Games Won: %d\n", player->totalWins);
	printf("Games Lost: %d\n", player->totalLosses);

	float winRate = ((float)player->totalWins) / ((float)player->gamesPlayed);
	printf("Win Percentage: %f\n", winRate * 100.f);
}

void DestroyPlayer(Player* player) {
	free(player);
}