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
		
		TEST_METHOD(SetCharacterAtCurrentPosition1)
		{
			GameBoard g;
			g.currentColumn = 4;
			g.currentRow = 5;
			SetCharacterAtCurrentPosition(&g, 'f');
			Assert::AreEqual(g.grid[4][5], 'f');
		}
		TEST_METHOD(SetCharacterAtCurrentPosition2)
		{
			GameBoard g;
			g.currentColumn = 4;
			g.currentRow = 5;
			SetCharacterAtCurrentPosition(&g, 'f');
			Assert::AreNotEqual(g.grid[4][5], 'g');
		}
		TEST_METHOD(SetCharacterAtCurrentPosition3)
		{
			GameBoard g;
			g.currentColumn = 4;
			g.currentRow = 5;
			SetCharacterAtCurrentPosition(&g, 'f');
			Assert::AreNotEqual(g.grid[0][0], 'f');
		}
		TEST_METHOD(GetCharacterAtCurrentPosition1)
		{
			GameBoard g;
			g.currentColumn = 4;
			g.currentRow = 5;
			SetCharacterAtCurrentPosition(&g, 'f');
			char temp = GetCharacterAtCurrentPosition(&g);
			Assert::AreEqual(temp, 'f');
		}
		TEST_METHOD(GetCharacterAtCurrentPosition2)
		{
			GameBoard g;
			g.currentColumn = 4;
			g.currentRow = 5;
			SetCharacterAtCurrentPosition(&g, 'f');
			g.currentColumn = 0;
			g.currentRow = 0;
			char temp = GetCharacterAtCurrentPosition(&g);
			Assert::AreNotEqual(temp, 'f');
		}
	};
}
