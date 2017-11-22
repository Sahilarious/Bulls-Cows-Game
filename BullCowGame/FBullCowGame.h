#pragma once
#include <string>


class FBullCowGame {

public:
	FBullCowGame(int WordLength);

	int GetMaxTries() const;
	int GetCurrentTries() const;
	bool IsGameWon() const;
	int GetWordLength() const;

	void Reset(int WordLength);
	bool IsGuessValid(std::string Guess);

private:
	int MyMaxTries;
	int MyCurrentTries = 1;
	int MyWordLength;
	bool bIsIsogram(std::string Guess) const;



};