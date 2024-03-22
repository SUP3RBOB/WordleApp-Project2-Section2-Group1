#define _CRT_SECURE_NO_WARNINGS
#include "mainmenu.h"
#include <stdlib.h>
#include <conio.h>
#include "stdio.h"

#define ARROW_KEY 224
#define UP_ARROW 72
#define DOWN_ARROW 80
#define KEY_ENTER 13

char input = {'a'};

void PrintLogo() {
	for (int i = 0; i < 5; i++)
	{
		printf("\n");
	}
	printf("              WWWWW    WWW    WWWWW      OOOOOOOO        RRRRRRRRR       DDDDDDD       LLL          EEEEEE\n");
	printf("               WWWWW  WWWWW  WWWWW     OOOO    OOOO      RRR    RRR      DDD   DDD     LLL          EEE\n");
	printf("                WWWWWWWW WWWWWWWW     OOOO      OOOO     RRRRRRRRR       DDD    DD     LLL          EEEEEE\n");
	printf("                 WWWWWW   WWWWWW       OOOO    OOOO      RRR   RRRR      DDD   DDD     LLL          EEE\n");
	printf("                  WWWW     WWWW          OOOOOOOO        RRR     RRR     DDDDDDD       LLLLLLLL     EEEEEE\n");
	for (int i = 0; i < 4; i++)
	{
		printf("\n");
	}
	//printf("                                               input three letters for a name\n");
	//printf("                                                           Q to quit\n");
	//printf("                                                   or press space to begin\n");
}

void UpdateMenu(MainMenu* menu) {
	int input = _getch();

	if (input == ARROW_KEY) {
		input = _getch();
		if (input == UP_ARROW || input == DOWN_ARROW) {
			menu->index = 0 + (++(menu->index) % 2);
		}
	} else if (input == KEY_ENTER) {
		if (menu->index == 0) {
			menu->exitMenu = true;
		} else {
			menu->running = false;
			menu->exitMenu = false;
		}
	}
}

void RefreshMenu(MainMenu* menu) {
	system("cls");
	PrintLogo();
	printf("\t\t\t\t\t\t\tPlay\t");

	if (menu->index == 0) {
		printf("<-");
	}

	printf("\n");
	printf("\t\t\t\t\t\t\tQuit\t");

	if (menu->index == 1) {
		printf("<-");
	}

	printf("\n");
}

void start() {
	system("cls");
}

void quit() {
	exit(0);
}

void setName(Player* info, char name[USERNAME_LENGTH]) {
	strncpy(info->username, name, USERNAME_LENGTH);
}
