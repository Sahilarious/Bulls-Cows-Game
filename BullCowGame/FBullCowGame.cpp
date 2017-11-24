#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_GUESSES = 5;
	MyMaxTries = MAX_GUESSES;

	const FString MYSTERY_WORD = "AIR";
	MyMysteryWord = ToLowerCase(MYSTERY_WORD);

	MyMaxTries = MAX_GUESSES;



	MyCurrentTries = 1;

	return;
}
// Getter method
int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

// Getter method
int32 FBullCowGame::GetCurrentTries() const
{
	return MyCurrentTries;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) const
{
	Guess = ToLowerCase(Guess);
	FBullCowCount BullCowCount;
	for (int32 i = 0; i < GetWordLength(); i++)
	{
		for (int32 j = 0; j < GetWordLength(); j++)
		{
			if (Guess[i] == MyMysteryWord[j]) 
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
				j = GetWordLength() + 1;
			}
		}
	}

	return BullCowCount;
}


std::list<EWordStatus> FBullCowGame::IsGuessValid(FString Guess)
{
	bool IsCorrectLength = Guess.length() == GetWordLength();
	bool IsIsogram = this->bIsIsogram(Guess);
	bool IsAlphabetical = CheckIfAlphabetical(Guess);

	std::list<EWordStatus> ErrorList;

	if (!IsCorrectLength) {
		ErrorList.push_back(EWordStatus::Incorrect_Length);
	}
	
	if(!IsIsogram)
	{
		ErrorList.push_back(EWordStatus::Guess_Not_Isogram);
	}

	if (!IsAlphabetical) {
		ErrorList.push_back(EWordStatus::Non_Letter_Chars);
	}


	if (ErrorList.size() == 0) {
		MyCurrentTries++;
		ErrorList.push_back(EWordStatus::OK);
	}

	return ErrorList;


}

// Getter method
bool FBullCowGame::IsGameWon(FString Guess) const
{
	bool GameWon = (MyMysteryWord == Guess);
	return GameWon;
}

// Getter method
int32 FBullCowGame::GetWordLength() const
{
	return MyMysteryWord.length();
}


// Getter method
bool FBullCowGame::bIsIsogram(FString Guess) const
{
	int32 GuessLength = Guess.length();
	for (int32 i = 0; i < GuessLength - 1; i++)
	{
		for (int32 j = i + 1; j < GuessLength; j++)
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

FString FBullCowGame::ToLowerCase(FString Guess) const
{
	FString LCString = "";

	for (int i = 0; i < Guess.length(); i++) 
	{
		LCString = LCString + (char)tolower(Guess[i]);
	}

	return LCString;
}


bool FBullCowGame::CheckIfAlphabetical(FString Guess) const
{
	for (char MyChar : Guess) {
		if (!isalpha(MyChar)) {
			return false;
		}
	}
	return true;
}



