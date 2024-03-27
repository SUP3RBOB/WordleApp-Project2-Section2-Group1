#pragma once
#include "stdbool.h"
#define USERNAME_LENGTH 4

typedef struct player {
	char username[USERNAME_LENGTH];
	int gamesPlayed;
	int totalWins;
	int totalLosses;
	int winStreak;
	int highestWinStreak;
} Player;

Player* CreatePlayer();
bool SavePlayerData(Player* player, char fileName[]);
bool LoadPlayerData(Player* player, char fileName[]);
void PrintPlayerInfo(Player* player);
void DestroyPlayer(Player* player);