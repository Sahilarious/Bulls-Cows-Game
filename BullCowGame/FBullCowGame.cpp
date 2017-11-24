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

	bGameWon = false;

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

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	Guess = ToLowerCase(Guess);
	FBullCowCount BullCowCount;
	int32 WordLength = GetMysteryWordLength();

	if (Guess.length() == WordLength) {

		for (int32 i = 0; i < WordLength; i++)
		{
			for (int32 j = 0; j < WordLength; j++)
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
					j = WordLength + 1;
				}
			}
		}
	}

	if (BullCowCount.Bulls == WordLength) {
		bGameWon = true;
	}

	return BullCowCount;
}


std::list<EWordStatus> FBullCowGame::IsGuessValid(FString Guess)
{
	bool IsCorrectLength = Guess.length() == GetMysteryWordLength();
	bool IsIsogram = bIsIsogram(Guess);
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
bool FBullCowGame::IsGameWon() const
{
	return bGameWon;
}

// Getter method
int32 FBullCowGame::GetMysteryWordLength() const
{
	return MyMysteryWord.length();
}


// Getter method
bool FBullCowGame::bIsIsogram(FString Guess) const
{
	int32 GuessLength = Guess.length();

	if (GuessLength > 1) 
{
		Guess = ToLowerCase(Guess);

		TMAP<char, bool> LettersInGuess;

		for (auto Letter : Guess)
		{
			if (LettersInGuess[Letter])
			{
				return false;
			}
			LettersInGuess[Letter] = true;
		}
	}
	return true;
}

FString FBullCowGame::ToLowerCase(FString Guess) const
{
	FString LCString = "";

	for (auto Letter : Guess) 
	{
		LCString = LCString + (char)tolower(Letter);
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



