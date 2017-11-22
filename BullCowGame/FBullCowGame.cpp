#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(int WordLength)
{
	Reset(WordLength);
}

void FBullCowGame::Reset(int WordLength)
{
	constexpr int MAX_GUESSES = 8;


	MyMaxTries = MAX_GUESSES;
	MyWordLength = WordLength;


	MyCurrentTries = 1;

	return;
}
// Getter method
int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

// Getter method
int FBullCowGame::GetCurrentTries() const
{
	return MyCurrentTries;
}

bool FBullCowGame::IsGuessValid(std::string Guess)
{
	
	if (Guess.length() != MyWordLength) {
		return false;
	}
	MyCurrentTries++;

	return true;
}

// Getter method
bool FBullCowGame::IsGameWon() const
{
	return false;
}

// Getter method
int FBullCowGame::GetWordLength() const
{
	return MyWordLength;
}

// Getter method
bool FBullCowGame::bIsIsogram(std::string Guess) const
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
