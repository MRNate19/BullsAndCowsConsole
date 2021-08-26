#pragma once

std::string GetGuess();

void CheckGuess(std::string Guess, std::string Isotope);
void StartGame();
void Error(std::string S);

struct BullsAndCowsCount
{
	int Bulls;
	int Cows;

	BullsAndCowsCount();
};

