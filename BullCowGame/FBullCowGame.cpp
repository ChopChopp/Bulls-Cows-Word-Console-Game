#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { 
	return MyMaxTries; 
}
int32 FBullCowGame::GetCurrentTry() const { 
	return MyCurrentTry; 
}
int32 FBullCowGame::GetHiddenWordLength() const {
	return MyHiddenWord.length();
}
bool FBullCowGame::IsGameWon() const{
	return bGameIsWon;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (false) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}

}

//receives a VALID guess, increments turn, and returns counts
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	//loop through all letters in the guess
	for (int32 i = 0; i < MyHiddenWord.length(); i++) {
		for (int32 j = 0; j < MyHiddenWord.length(); j++) {
			if (Guess[i] == MyHiddenWord[j]) {
				if (j == i) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	// compare letters against the hidden word
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}
