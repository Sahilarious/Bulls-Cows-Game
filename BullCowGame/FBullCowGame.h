#pragma once
#include <string>
#include <list>




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
	Guess_Not_Isogram, 
	Incorrect_Length,
	Non_Letter_Chars

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
	std::list<EWordStatus> IsGuessValid(FString Guess);

private:
	int32 MyMaxTries;
	int32 MyCurrentTries = 1;
	bool bIsIsogram(FString Guess) const;
	
	FString MyMysteryWord = "";

	FString ToLowerCase(FString Guess) const;
	bool CheckIfAlphabetical(FString Guess) const;
};