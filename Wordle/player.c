#include "player.h"
#include <stdio.h>
#include <stdlib.h>

Player* CreatePlayer() {
	Player* player = malloc(sizeof(Player));
	if (player == NULL) {
		fprintf(stderr, "Not enough memory to create player");
		return NULL;
	}

	player->gamesPlayed = 0;
	player->totalWins = 0;
	player->totalLosses = 0;
	player->winPercentage = 0.0f;
	player->winStreak = 0;

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
		fprintf(stderr, "Unable to open file %s for loading", fileName);
		return false;
	}

	fread(player, sizeof(Player), 1, fp);

	return true;
}

void DestroyPlayer(Player* player) {
	free(player);
}