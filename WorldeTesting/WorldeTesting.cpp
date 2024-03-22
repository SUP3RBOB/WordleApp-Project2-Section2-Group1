#include "pch.h"
#include "CppUnitTest.h"

#define BOARD_WIDTH 5
#define BOARD_HEIGHT 6

//for the Game file
//extern "C"___; fill in blank with any functions we be testing

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" typedef enum letterStatus { NotInWord, IsInWord, IsInPosition, } LetterStatus;
extern "C" typedef struct game {bool running;bool gameEnded;bool gameWon;char word[6];} Game;
extern "C" typedef struct gameBoard {char grid[BOARD_WIDTH][BOARD_HEIGHT];int currentRow;int currentColumn;} GameBoard;


extern "C" bool DestroyGame(Game * game);
extern "C" bool GetInputs(Game * game, GameBoard * gameBoard);
extern "C" bool ReplayGame(Game* game, GameBoard* gameBoard);
extern "C" void RefreshBoard(GameBoard* gameBoard);
extern "C" bool IsValidInput(char letter);
extern "C" bool IsLetterInWord(char letter);
extern "C" LetterStatus GetLetterCase(char letter, int pos);
extern "C" bool WordFound(GameBoard* gameBoard);

namespace WorldeTesting
{
	TEST_CLASS(WorldeTesting)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//Assert::
		}
	};
}
