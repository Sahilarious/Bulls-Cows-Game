#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\BullCowGame\FBullCowGame.h"
#include <list>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace BullCowGameTests
{		


	TEST_CLASS(FBullCowGameTests)
	{

	public:
		FBullCowGame BCGame = FBullCowGame();
		
		
		TEST_METHOD(IsGuessValid)
		{
			std::string Guess = "blu";
			
			std::list<EWordStatus> Result = BCGame.IsGuessValid(Guess);
			
			EWordStatus ExpectedResult = EWordStatus::OK;

			bool bExpectedResult = ExpectedResult == EWordStatus::OK;

			bool bResult = Result.front() == EWordStatus::OK;

			Assert::AreEqual(bExpectedResult, bResult, L"message", LINE_INFO());
		}

	};
}