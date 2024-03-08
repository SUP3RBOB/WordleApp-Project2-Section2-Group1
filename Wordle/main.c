#include <stdio.h>
#include "game.h"
#include "mainmenu.h"

int main() {
	char input[4];
	GameBoard* gameBoard = CreateGameBoard();
	//p info;

	//main menu begin
	//printf("        welcome to worlde!        \n");
	for (int i = 0; i < 5; i++)
	{
		printf("\n");
	}
	printf("              WWWWW    WWW    WWWWW      OOOOOOOO        RRRRRRRRR       DDDDDDD       LLL          EEEEEE\n");
	printf("               WWWWW  WWWWW  WWWWW     OOOO    OOOO      RRR    RRR      DDD   DDD     LLL          EEE\n");
	printf("                WWWWWWWW WWWWWWWW     OOOO      OOOO     RRRRRRRRR       DDD    DD     LLL          EEEEEE\n");
	printf("                 WWWWWW   WWWWWW       OOOO    OOOO      RRR   RRRR      DDD   DDD     LLL          EEE\n");
	printf("                  WWWW     WWWW          OOOOOOOO        RRR     RRR     DDDDDDD       LLLLLLLL     EEEEEE\n");
	for (int i = 0; i < 9; i++)
	{
		printf("\n");
	}
	printf("                                               input three letters for a name\n");
	printf("                                                   or press space to begin\n");
	/*fgets(input, 4, stdin);

	if (input == " ")
	{
		start();
	}if (input == "Q") {
		quit();
	}else{
			setName(info, input);
	}*/
	
	//main menu end
	while (true) {
		GetInputs(gameBoard);
	}

	DestroyGameBoard(gameBoard);
	return 0;
}