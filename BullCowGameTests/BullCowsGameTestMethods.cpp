#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\BullCowGame\FBullCowGame.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace BullCowGameTests
{		
	TEST_CLASS(FBullCowGameTests)
	{
	public:
		
		TEST_METHOD(IsIsomorph)
		{
			std::string Guess = "bagel";
			bool expectedResult = true;
			bool result = CheckIsIsomorph(Guess);

			Assert::AreEqual(expectedResult, result, L"message", LINE_INFO());
		}


		bool CheckIsIsomorph(std::string Guess) 
		{
		
			int GuessLength = Guess.length();
			for (int i = 0; i < GuessLength - 1; i++)
			{
				for (int j = i + 1; j < GuessLength; j++)
				{
					if (i != j)
					{
						if (Guess[i] == Guess[j]) {
							return false;
						}
					}
				}
			}

			return true;
		}


	};
}