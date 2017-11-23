#pragma once
#include <string>


using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	OK,
	Not_Isogram,
	Incorrect_Length,
};

enum class EResetStatus
{
	OK,
	No_Hidden_Word
};

class FBullCowGame {

public:
	FBullCowGame::FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTries() const;
	bool IsGameWon(FString Guess) const;
	int32 GetWordLength() const;
	FBullCowCount SubmitGuess(FString Guess) const;

	void Reset();
	EWordStatus IsGuessValid(FString Guess);

private:
	int32 MyMaxTries;
	int32 MyCurrentTries = 1;
	bool bIsIsogram(FString Guess) const;
	
	FString MyMysteryWord = "";

};