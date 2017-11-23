#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\BullCowGame\FBullCowGame.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace BullCowGameTests
{		


	TEST_CLASS(FBullCowGameTests)
	{

	public:
		FBullCowGame BCGame = FBullCowGame(5);
		
		
		TEST_METHOD(IsGuessValid)
		{
			std::string Guess = "blues";
			
			bool result = BCGame.IsGuessValid(Guess);
			
			bool expectedResult = true;


			Assert::AreEqual(expectedResult, result, L"message", LINE_INFO());
		}

	};
}