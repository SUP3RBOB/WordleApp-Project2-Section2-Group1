#pragma once
#include "stdio.h"
#include "string.h"
#include "player.h"
#define MAX 3
#define LIMIT 1

typedef struct mainMenu {
	int index;
	bool running;
	bool exitMenu;
} MainMenu;

void PrintLogo();

void UpdateMenu(MainMenu* menu);
void RefreshMenu(MainMenu* menu);

void start();

void quit();

void setName(Player* info, char name[USERNAME_LENGTH]);