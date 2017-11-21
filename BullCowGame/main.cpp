// libraries like iostream can contain more than one namespaces
#include <iostream>
#include <string>
#include <algorithm>
#include "FBullCowGame.h"

// std --> standard namespace

constexpr int WORD_LENGTH = 7;

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool CheckIsValidGuess(std::string Guess);
bool AskToPlayAgain();

FBullCowGame BCGame = FBullCowGame(WORD_LENGTH);


int main() 
{
	bool bPlayAgain = false;
	do 
	{
		BCGame.Reset(WORD_LENGTH);
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
	int MaxGuesses = BCGame.GetMaxTries();
	std::cout << MaxGuesses << std::endl;

	for (int i = 1; i <= MaxGuesses; i++) {
		bool bIsValid;

		do {
			std::string PlayerGuess = GetGuess();
			bIsValid = BCGame.IsGuessValid(PlayerGuess);

			//if guess is valid, print number of bulls and cows 

		} while (!bIsValid);
	}

	return;
}

// Take a guess from the player
std::string GetGuess()
{
	int CurrentGuess = BCGame.GetCurrentTries();
	std::cout << "Enter guess " << CurrentGuess << ": ";
	std::string Guess = "";
	
	getline(std::cin, Guess);

	return Guess;
}

// Repeat the guess back to the user
bool CheckIsValidGuess(std::string Guess)
{
	bool IsGuessValid = BCGame.IsGuessValid(Guess);
	if (!IsGuessValid) {
		std::cout << "Your guess, " << Guess <<  ", is not valid, try again." << std::endl;
		return false;
	}
	std::cout << "Your guess is: " << Guess << std::endl;

	return true;
}

bool AskToPlayAgain()
{
	while (true) {
		std::cout << "Play Again? (Y/N)" << std::endl;
		std::string ChoicePlayAgain;
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

