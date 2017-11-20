// libraries like iostream can contain more than one namespaces
#include <iostream>
#include <string>
#include <algorithm>

// std --> standard namespace
using namespace std;


constexpr int WORD_LENGTH = 5;
constexpr int MAX_GUESSES = 5;

void PrintIntro();
void PlayGame();
string GetGuess();
bool IsValidGuess(string Guess);
bool AskToPlayAgain();


int main() 
{
	bool PlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		PlayAgain = AskToPlayAgain();
	} 
	while (PlayAgain);

	return 0;
}

// Introduce the game
void PrintIntro() 
{
	

	// cout --> character out
	// << --> overloaded operator
	cout << "Welcome to Bulls and Cows, a super cool word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;
	return;
}

// Repeat input/output of guesses for the number of turns
void PlayGame() 
{

	for (int i = 1; i <= MAX_GUESSES; i++) {
		bool IsValid;

		do {
			string PlayerGuess = GetGuess();
			IsValid = IsValidGuess(PlayerGuess);
		} while (!IsValid);
	}

	return;
}

// Take a guess from the player
string GetGuess() 
{
	cout << "Enter your guess: ";
	string Guess;
	getline(cin, Guess);

	return Guess;
}

// Repeat the guess back to the user
bool IsValidGuess(string Guess) 
{
	if (Guess.length() != WORD_LENGTH) {
		cout << "Your guess, " << Guess <<  ", is not valid, try again." << endl;
		return false;
	}
	cout << "Your guess is: " << Guess << endl;

	return true;
}

bool AskToPlayAgain()
{
	while (true) {
		cout << "Play Again? (Y/N)" << endl;
		string ChoicePlayAgain;
		getline(cin, ChoicePlayAgain);
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
			cout << "Answer is not valid. Try again." << endl;
		}
	}
}

