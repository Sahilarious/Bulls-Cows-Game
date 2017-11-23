/*
	Console executable that serves as the interface for user interaction.
	Equivalent to the View of the MVC design pattern.
*/


// libraries like iostream can contain more than one namespaces
#include <iostream>
#include <string>
#include <algorithm>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

constexpr int32 WORD_LENGTH = 5;

void PrintIntro();
void PlayGame();
FText GetGuess();
void CheckIsValidGuess(FText Guess, EWordStatus GuessValid);
bool AskToPlayAgain();

FBullCowGame BCGame;


int main() 
{
	bool bPlayAgain = false;
	do 
	{
		std::cout << std::endl;
		BCGame.Reset();
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0;
}

// Introduce the game
void PrintIntro() 
{
	// cout --> character out
	// << --> overloaded operator
	std::cout << "Welcome to Bulls and Cows, a super cool word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetWordLength() << " letter isogram I'm thinking of?" << std::endl;
	return;
}

// Repeat input/output of guesses for the number of turns
void PlayGame() 
{
	int32 MaxGuesses = BCGame.GetMaxTries();

	bool GameWon = false;

	//for (int32 i = 1; i <= MaxGuesses; i++) {
	while(BCGame.GetCurrentTries() <= MaxGuesses && !GameWon)
	{ 
		std::cout << std::endl;
		
		EWordStatus IsValid;

		do {
			FText PlayerGuess = GetGuess();
			IsValid = BCGame.IsGuessValid(PlayerGuess);

			CheckIsValidGuess(PlayerGuess, IsValid);

			//if guess is valid, print number of bulls and cows 
			if (IsValid == EWordStatus::OK)
			{
				FBullCowCount Results = BCGame.SubmitGuess(PlayerGuess);
				std::cout << "Bulls: " << Results.Bulls << std::endl;
				std::cout << "Cows: " << Results.Cows << std::endl;

				GameWon = BCGame.IsGameWon(PlayerGuess);
			}

			
		} while (IsValid != EWordStatus::OK);
		

	}

	if (GameWon) {
		std::cout << "\nYou win!!!!" << std::endl;
	}
	else 
	{
		std::cout << "\nYou lose." << std::endl;
	}

	return;
}

// Take a guess from the player
FText GetGuess()
{
	int32 CurrentGuess = BCGame.GetCurrentTries();
	std::cout << "Enter guess " << CurrentGuess << ": ";
	FText Guess = "";
	
	getline(std::cin, Guess);

	return Guess;
}

// Repeat the guess back to the user
void CheckIsValidGuess(FText Guess, EWordStatus GuessValid)
{

	switch (GuessValid) {
	case EWordStatus::Incorrect_Length:
		std::cout << "Error: Guess entered" << Guess << ", is of incorrect length." << std::endl;
		break;
	case EWordStatus::Not_Isogram:
		std::cout << "Error: Guess entered," << Guess << ", is not an isogram." << std::endl;
		break;
	}


	return;
}

bool AskToPlayAgain()
{
	while (true) {
		std::cout << "Play Again? (Y/N)" << std::endl;
		FText ChoicePlayAgain;
		getline(std::cin, ChoicePlayAgain);
		ChoicePlayAgain = tolower(ChoicePlayAgain[0]);

		if (ChoicePlayAgain == "y")
		{
			return true;
		}
		else if (ChoicePlayAgain == "n")
		{
			return false;
		}
		else
		{
			std::cout << "Answer is not valid. Try again." << std::endl;
		}
	}
}

