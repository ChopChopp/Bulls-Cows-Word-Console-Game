#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

//receives a VALID guess, increments turn, and returns counts
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	//increment the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	
	//loop through all letters in the guess
		// compare letters against the hidden word
	return BullCowCount;
}
