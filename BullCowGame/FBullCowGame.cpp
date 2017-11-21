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

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

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


bool FBullCowGame::IsGameWon() const
{
	return false;
}

int FBullCowGame::GetWordLength() const
{
	return MyWordLength;
}

bool FBullCowGame::bIsIsogram() const
{
	return false;
}
