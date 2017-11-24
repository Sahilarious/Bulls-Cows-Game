/*
	Console executable that serves as the interface for user interaction.
	Equivalent to the View of the MVC design pattern.
*/


// libraries like iostream can contain more than one namespaces
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

constexpr int32 WORD_LENGTH = 5;

void PrintIntro();
void PlayGame();
FText GetGuess();
void ErrorGuess(FText Guess, std::list<EWordStatus> GuessValidList);
void PrintGameEnding();
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
		PrintGameEnding();
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
	std::cout << "Can you guess the " << BCGame.GetMysteryWordLength() << " letter isogram I'm thinking of?" << std::endl;
	return;
}

// Repeat input/output of guesses for the number of turns
void PlayGame() 
{
	int32 MaxGuesses = BCGame.GetMaxTries();



	//for (int32 i = 1; i <= MaxGuesses; i++) {
	while(BCGame.GetCurrentTries() <= MaxGuesses && !BCGame.IsGameWon())
	{ 
		std::cout << std::endl;
		
		std::list<EWordStatus> IsValidList;

		do {
			FText PlayerGuess = GetGuess();

			IsValidList = BCGame.IsGuessValid(PlayerGuess);
			

			//if guess is valid, print number of bulls and cows 
			if (IsValidList.front() == EWordStatus::OK)
			{
				FBullCowCount Results = BCGame.SubmitValidGuess(PlayerGuess);
				std::cout << "Bulls: " << Results.Bulls << std::endl;
				std::cout << "Cows: " << Results.Cows << std::endl;

			}
			else {
				ErrorGuess(PlayerGuess, IsValidList);
			}

		} while (IsValidList.front() != EWordStatus::OK);

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
void ErrorGuess(FText Guess, std::list<EWordStatus> GuessValidList)
{
	for (EWordStatus error : GuessValidList) {
		switch (error) {
		case EWordStatus::Incorrect_Length:
			std::cout << "Error: Guess entered, " << Guess << ", is of incorrect length." << std::endl;
			break;
		case EWordStatus::Guess_Not_Isogram:
			std::cout << "Error: Guess entered, " << Guess << ", is not an isogram." << std::endl;
			break;
		case EWordStatus::Non_Letter_Chars:
			std::cout << "Error: Guess entered, " << Guess << ", must contain alphabetical characters only." << std::endl;
			break;
		default:
			break;
		}
	}

	return;
}

void PrintGameEnding() {
	if (BCGame.IsGameWon()) {
		std::cout << "\nYou win!!!!" << std::endl;
	}
	else
	{
		std::cout << "\nYou lose." << std::endl;
	}
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

