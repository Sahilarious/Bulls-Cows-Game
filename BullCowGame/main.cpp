// libraries like iostream can contain more than one namespaces
#include <iostream>
#include <string>
#include <algorithm>
#include "FBullCowGame.h"

// std --> standard namespace

constexpr int WORD_LENGTH = 5;
constexpr int MAX_GUESSES = 5;

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool CheckIsValidGuess(std::string Guess);
bool AskToPlayAgain();


int main() 
{
	bool bPlayAgain = false;
	do 
	{
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
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
	return;
}

// Repeat input/output of guesses for the number of turns
void PlayGame() 
{
	FBullCowGame BCGame = FBullCowGame();
	for (int i = 1; i <= MAX_GUESSES; i++) {
		bool bIsValid;

		do {
			std::string PlayerGuess = GetGuess();
			bIsValid = CheckIsValidGuess(PlayerGuess);
		} while (!bIsValid);
	}

	return;
}

// Take a guess from the player
std::string GetGuess()
{
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	
	getline(std::cin, Guess);

	return Guess;
}

// Repeat the guess back to the user
bool CheckIsValidGuess(std::string Guess)
{
	if (Guess.length() != WORD_LENGTH) {
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

