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
		TEST_METHOD(NextRow1)
		{
			GameBoard *g;
			g = NULL;
			bool temp = NextRow(g);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(NextRow2)
		{
			GameBoard g;
			g.currentColumn = 0;
			g.currentRow = 0;
			NextRow(&g);
			SetCharacterAtCurrentPosition(&g, 'f');
			Assert::AreNotEqual(g.grid[0][0], 'f');
		}
		TEST_METHOD(ResetBoard1)
		{
			GameBoard g;
			ResetBoard(&g);
			Assert::AreEqual(g.grid[0][0], ' ');
		}
		TEST_METHOD(ResetBoard2)
		{
			GameBoard g;
			ResetBoard(&g);
			Assert::AreEqual(g.grid[4][5], ' ');
		}
		TEST_METHOD(ResetBoard3)
		{
			GameBoard g;
			g.currentColumn = 0;
			g.currentRow = 0;
			SetCharacterAtCurrentPosition(&g, 'f');
			ResetBoard(&g);
			Assert::AreNotEqual(g.grid[0][0], 'f');
		}
		TEST_METHOD(ResetBoard4)
		{
			GameBoard g;
			g.currentColumn = 4;
			g.currentRow = 5;
			SetCharacterAtCurrentPosition(&g, 'f');
			ResetBoard(&g);
			Assert::AreNotEqual(g.grid[4][5], 'f');
		}
		TEST_METHOD(DestroyGameBoard1)
		{
			GameBoard *g;
			g = NULL;
			bool temp = DestroyGameBoard(g);
			Assert::AreEqual(temp, false);
		}
		TEST_METHOD(DestroyGameBoard2)
		{
			GameBoard g;
			g.currentColumn = 4;
			g.currentRow = 5;
			SetCharacterAtCurrentPosition(&g, 'f');
			bool temp = DestroyGameBoard(&g);
			Assert::AreEqual(temp, true);
		}
	};
}
