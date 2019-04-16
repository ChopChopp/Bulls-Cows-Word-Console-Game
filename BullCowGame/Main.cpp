/*	This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/


#include  <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCgame;


int main() {

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}


void PrintIntro() {
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	BCgame.Reset();
	// loop for the number of turns asking for guess
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int32 i = 0; i < BCgame.GetMaxTries(); i++) {
		FText Guess = GetGuess(); //TODO make loop checking valid
		// submit valid guess to the game
		// print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	// TODO summarise game
}


bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}


FText GetGuess() {

	std::cout << "Try " << BCgame.GetCurrentTry() << ": Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}


