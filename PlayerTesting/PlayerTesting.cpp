#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define USERNAME_LENGTH 4

//player struct
extern "C" typedef struct player {char username[USERNAME_LENGTH];int gamesPlayed;int totalWins;int totalLosses;float winPercentage;int winStreak;} Player;

//main menu prototype
extern "C" void setName(Player* info, char name[USERNAME_LENGTH]);

//player prototypes
extern "C" bool SavePlayerData(Player * player, char fileName[]);
extern "C" bool LoadPlayerData(Player * player, char fileName[]);



namespace PlayerTesting
{
	TEST_CLASS(PlayerTesting)
	{
	public:
		
		TEST_METHOD(NameSet1)
		{
			Player p;
			char name[USERNAME_LENGTH] = "Yaa";
			setName(&p, name);
			int n = strncmp(name, p.username, USERNAME_LENGTH);
			Assert::AreEqual(n, 0);
		}
		TEST_METHOD(SavePlayer1)
		{
			Player p;
			char name[] = "randomfile.txt";
			bool geuss = SavePlayerData(&p, name);
			Assert::AreEqual(geuss, true);
		}
		TEST_METHOD(LoadPlayer1)
		{
			Player p;
			char name[] = "randomassfile.txt";
			bool geuss = LoadPlayerData(&p, name);
			Assert::AreEqual(geuss, true);
		}
		TEST_METHOD(LoadPlayer2)
		{
			Player p;
			char name[] = "random.txt";
			bool geuss = LoadPlayerData(&p, name);
			Assert::AreEqual(geuss, false);
		}
	};
}
