#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // TODO make a more richt return value.
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); //TODO make a more richt return value

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};