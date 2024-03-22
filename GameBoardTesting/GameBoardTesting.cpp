#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define BOARD_WIDTH 5
#define BOARD_HEIGHT 6

extern "C" typedef struct gameBoard {char grid[BOARD_WIDTH][BOARD_HEIGHT];int currentRow;int currentColumn;} GameBoard;

extern "C" void SetCharacterAtCurrentPosition(GameBoard* gameBoard, char c);
extern "C" char GetCharacterAtCurrentPosition(GameBoard* gameBoard);
extern "C" bool NextRow(GameBoard* gameBoard);
extern "C" bool ResetBoard(GameBoard* board);
extern "C" bool DestroyGameBoard(GameBoard* gameBoard);

namespace GameBoardTesting
{
	TEST_CLASS(GameBoardTesting)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			GameBoard g;
			g.currentColumn = 5;
			g.currentRow = 6;
			SetCharacterAtCurrentPosition(&g, 'f');
			Assert::AreEqual(g.grid[5][6], 'f');
		}
	};
}
