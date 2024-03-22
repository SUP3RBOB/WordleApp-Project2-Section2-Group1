#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" void setName(Player * info, char name[USERNAME_LENGTH]);

namespace MainMenuTesting
{
	TEST_CLASS(MainMenuTesting)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};
}
