#pragma once
#include <string>


class FBullCowGame {

public:
	void Reset(int WordLength); 
	int GetMaxTries();
	int GetCurrenTry();
	bool IsGuessValid(std::string);
	bool IsGameWon();
	int GetWordLength();

private:
	int MyCurrentTry;
	int MyMaxTries;
	int WordLength;
	bool bIsIsogram();



};