#pragma once

class BullsAndCowsGame
{
public:
	int Lives;
	bool IsGameOver;
	void ResetLives();

	BullsAndCowsGame();
	void DecrementLives();
	int GetLives() const;	
};
