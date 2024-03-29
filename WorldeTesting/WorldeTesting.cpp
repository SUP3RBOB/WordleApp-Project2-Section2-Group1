#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>

#define BOARD_WIDTH 5
#define BOARD_HEIGHT 6
#define WORD_LENGTH 6
#define VALID_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

//for the Game file
//extern "C"___; fill in blank with any functions we be testing

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" typedef enum letterStatus { NotInWord, IsInWord, IsInPosition, } LetterStatus;
extern "C" typedef struct game {bool running;bool gameEnded;bool gameWon;char word[6];} Game;
extern "C" typedef struct gameBoard {char grid[BOARD_WIDTH][BOARD_HEIGHT];int currentRow;int currentColumn;} GameBoard;


extern "C" bool DestroyGame(Game * game);
extern "C" bool IsValidInput(char letter);
extern "C" bool IsLetterInWord(char letter);
extern "C" LetterStatus GetLetterCase(char letter, int pos);
extern "C" bool WordFound(GameBoard* gameBoard);
extern "C" char word[];

namespace WorldeTesting {
	TEST_CLASS(WorldeTesting) {
	public:
		
		/*
		* Method to test whether the DestroyGame function succesfully destroys a game
		* Expected result: True
		* Actual Result: True
		*/
		TEST_METHOD(DestroyGameSuccess) {
			Game* g = (Game*)malloc(sizeof(Game));
			bool destroyed = DestroyGame(g);
			Assert::IsTrue(destroyed);
		}

		/*
		* Method to test the DestroyGame and see what happens when a blank pointer is inputted
		* Expected result: True
		* Actual Result: Build Error
		* Actual result after changes: Exception Code C0000005
		* The test method cannot test using the address of an uninitialized variable or pointer. An uninitialized pointer is not the same as NULL
		* Since there is no way to check if a vairable or pointer is initialized or not, we just removed this test method entirely
		*/
		/*TEST_METHOD(DestroyGameNoMalloc) {
			Game g;
			bool destroyed = DestroyGame(&g);
			Assert::AreEqual(destroyed, false);
		}*/

		/*
		* Method to test whether the DestroyGame will return false when NULL is inputted
		* Expected result: False
		* Actual Result: False
		*/
		TEST_METHOD(DestroyGameFailure) {
			Game* g = NULL;
			bool destroyed = DestroyGame(g);
			Assert::IsFalse(destroyed);
		}

		/*
		* Method to test if the WordFound function comapres the word with what is on the grid correctly
		* Expected result: True
		* Actual result: False
		* Result after changes: True
		* The variable word was not being imported properly from the C/H file. After some changes, the test method passed
		* The same applies for the other WordFound test methods
		*/
		TEST_METHOD(WordFoundSuccess) {
			strncpy(word, "WORLD", WORD_LENGTH);

			GameBoard g;
			g.currentColumn = 0;
			g.currentRow = 0;
			g.grid[0][0] = 'W';
			g.grid[1][0] = 'O';
			g.grid[2][0] = 'R';
			g.grid[3][0] = 'L';
			g.grid[4][0] = 'D';

			bool found = WordFound(&g);
			Assert::IsTrue(found);
		}

		/*
		* Method to test if the WordFound function comapres the word with what is on the grid incorrectly
		* Expected result: False
		* Actual result: False
		*/
		TEST_METHOD(WordFoundFailure) {
			strncpy(word, "WORLD", WORD_LENGTH);

			GameBoard g;
			g.currentColumn = 0;
			g.currentRow = 0;
			g.grid[0][0] = 'W';
			g.grid[1][0] = 'O';
			g.grid[2][0] = 'R';
			g.grid[3][0] = 'D';
			g.grid[4][0] = 'L';

			bool found = WordFound(&g);
			Assert::IsFalse(found);
		}

		/*
		* Method to test if the WordFound function comapres the word with case sensitivity (in this case we don't want it to)
		* Expected result: False
		* Actual result: False
		*/
		TEST_METHOD(WordFoundCaseSensitive) {
			strncpy(word, "WORLD", WORD_LENGTH);

			GameBoard g;
			g.currentColumn = 0;
			g.currentRow = 0;
			g.grid[0][0] = 'w';
			g.grid[1][0] = 'o';
			g.grid[2][0] = 'r';
			g.grid[3][0] = 'l';
			g.grid[4][0] = 'd';

			bool found = WordFound(&g);
			Assert::IsFalse(found);
		}

		/*
		* Method to test whether a character is in the word
		* Expected result: True
		* Actual Result: Build Error
		* The assert methods required the LetterStatus enum to have a valid to string method so that they could be compared
		* To fix this we instead we instead compared them outside the assert function and checked the result of the comparison instead
		* The same applies to the other GetLetterCase test methods
		*/
		TEST_METHOD(GetLetterCase_IsInWord) {
			strncpy(word, "WORLD", WORD_LENGTH);
			int pos = 1;
			char c = 'L';

			LetterStatus status = GetLetterCase(c, pos);
			bool inWord = status == IsInWord;
			Assert::IsTrue(inWord);
		}

		/*
		* Method to test whether a character is in the word and is in the specified position
		* Expected result: True
		* Actual Result: True
		*/
		TEST_METHOD(GetLetterCase_IsInWordAndPosition) {
			strncpy(word, "WORLD", WORD_LENGTH);
			int pos = 4;
			char c = 'D';

			LetterStatus status = GetLetterCase(c, pos);
			bool inWordAndPosition = status == IsInPosition;
			Assert::IsTrue(inWordAndPosition);
		}

		/*
		* Method to test whether a character is NOT in the word
		* Expected result: True
		* Actual Result: True
		*/
		TEST_METHOD(GetLetterCase_NotInWord) {
			strncpy(word, "WORLD", WORD_LENGTH);
			int pos = 2;
			char c = 'S';

			LetterStatus status = GetLetterCase(c, pos);
			bool isNotInWord = status == NotInWord;
			Assert::IsTrue(isNotInWord);
		}

		/*
		* Method to test whether a lower case version of a character is in the word
		* Expected result: False
		* Actual Result: False
		*/
		TEST_METHOD(GetLetterCase_IsInWord_CaseSensitive) {
			strncpy(word, "WORLD", WORD_LENGTH);
			int pos = 3;
			char c = 'o';

			LetterStatus status = GetLetterCase(c, pos);
			bool inWordAndPosition = status == IsInWord;
			Assert::IsFalse(inWordAndPosition);
		}

		/*
		* Method to test whether a lower case version of a character is in the word and in the specified position
		* Expected result: False
		* Actual Result: False
		*/
		TEST_METHOD(GetLetterCase_IsInWordAndPosition_CaseSensitive) {
			strncpy(word, "WORLD", WORD_LENGTH);
			int pos = 0;
			char c = 'w';

			LetterStatus status = GetLetterCase(c, pos);
			bool inWordAndPosition = status == IsInPosition;
			Assert::IsFalse(inWordAndPosition);
		}

		/*
		* Method to test if a letter is in the word
		* Expected result: True
		* Actual Result: True
		*/
		TEST_METHOD(IsLetterInWordSuccess) {
			strncpy(word, "WORLD", WORD_LENGTH);
			char c = 'O';

			bool inWord = IsLetterInWord(c);
			Assert::IsTrue(inWord);
		}

		/*
		* Method to test if a letter is NOT in the word
		* Expected result: False
		* Actual Result: False
		*/
		TEST_METHOD(IsLetterInWordFailure) {
			strncpy(word, "WORLD", WORD_LENGTH);
			char c = 'Z';

			bool inWord = IsLetterInWord(c);
			Assert::IsFalse(inWord);
		}

		/*
		* Method to test if a lowercase letter is in the word
		* Expected result: False
		* Actual Result: False
		*/
		TEST_METHOD(IsLetterInWord_CaseSensitive) {
			strncpy(word, "WORLD", WORD_LENGTH);
			char c = 'r';

			bool inWord = IsLetterInWord(c);
			Assert::IsFalse(inWord);
		}

		/*
		* Method to test if a character is a valid letter input
		* Expected result: True
		* Actual Result: True
		*/
		TEST_METHOD(IsValidInput_Character) {
			char c = 'A';

			bool valid = IsValidInput(c);
			Assert::IsTrue(valid);
		}

		/*
		* Method to test if a character is NOT a valid letter input
		* Expected result: False
		* Actual Result: False
		*/
		TEST_METHOD(IsValidInput_Other) {
			char c = ';';

			bool valid = IsValidInput(c);
			Assert::IsFalse(valid);
		}
	};
}
