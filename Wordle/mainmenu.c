#define _CRT_SECURE_NO_WARNINGS
#include "mainmenu.h"
#include <stdlib.h>
#include <conio.h>
#include "stdio.h"


char input = {'a'};



void start() {
	system("cls");
}

void quit() {
	exit(0);
}

void setName(Player* info, char name[USERNAME_LENGTH]) {
	strncpy(info->username, name, USERNAME_LENGTH);
}
