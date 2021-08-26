#include "BullsAndCows.h"

void BullsAndCowsGame::ResetLives()
{
	Lives = 4;
}

BullsAndCowsGame::BullsAndCowsGame()
{
	Lives = 4;
	IsGameOver = false;
}

void BullsAndCowsGame::DecrementLives()
{
	Lives--;
}

int BullsAndCowsGame::GetLives() const
{
	return Lives;
}

