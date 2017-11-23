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

	const FString MYSTERY_WORD = "waters";
	MyMysteryWord = MYSTERY_WORD;

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


EWordStatus FBullCowGame::IsGuessValid(FString Guess)
{
	bool IsCorrectLength = Guess.length() == GetWordLength();
	bool IsIsogram = this->bIsIsogram(Guess);

	if (!IsCorrectLength) {
		return EWordStatus::Incorrect_Length;
	}
	else if(!IsIsogram)
	{
		return EWordStatus::Not_Isogram;
	}

	MyCurrentTries++;

	return EWordStatus::OK;

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

