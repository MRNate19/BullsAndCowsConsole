//=========================================================================================================================
/*
* Written by Nathan Gardner.
* Date: 26/08/2021
*/

#include <iostream>
#include <string>
#include "BullsAndCows.h"
#include "main.h"

//=========================================================================================================================

BullsAndCowsGame Game;  // Global nonsense

//=========================================================================================================================
/*
* A data structure to keep track of the number of Bulls and Cows per guess
*/
//=========================================================================================================================

BullsAndCowsCount::BullsAndCowsCount()
{
	Bulls = 0;
	Cows = 0;
}

//=========================================================================================================================
/*
* To catch errors in Bulls and Cows we will use this function as a 1 catches all basis.
*/
//=========================================================================================================================

void Error(std::string S)
{
	throw std::runtime_error(S);
}

//=========================================================================================================================
/*
* Get user input and test to see that the istream object 'cin' is in a good state.
* Returns a string object (should be the player's guess!)
*/
//=========================================================================================================================

std::string GetGuess()
{
	std::string PlayerGuess;

	if (!std::cin)
		Error("Error: std::cin not in a good state");
	else
		std::cin >> PlayerGuess;

	return PlayerGuess;
}

//=========================================================================================================================
/*
* Checks the length of the players guess and compares it to the length of the Isotope
* 'returns' out of CheckGuess() if guess is a different length to Isotope
* Checks if player has guessed correctly
* Iterates through Isotope checking each letter against the players Guess to determine how
  many Bulls and Cows for current guess.
*/
//=========================================================================================================================

void CheckGuess(std::string Guess, std::string Isotope)
{
	BullsAndCowsCount Count;
	int IsotopeLength = Isotope.length();

	if (Guess.length() > IsotopeLength || Guess.length() < IsotopeLength)
	{
		std::cout << "Remember, the Isotope has " << IsotopeLength << " letters..." << std::endl;
		Game.DecrementLives();
		return;
	}

	if (Guess.compare(Isotope) == 0)
	{
		std::cout << "Well Done!" << std::endl;
	}
	else
	{
		for (int i = 0; i < Guess.length(); i++)
		{
			for (int j = 0; j < IsotopeLength; j++)
			{
				if (Guess[i] == Isotope[j])
				{
					if (i != j)
					{
						Count.Cows++;
					}
					else
					{
						Count.Bulls++;
					}
				}
			}
		}
	}

	std::cout << "Bulls: " << Count.Bulls << std::endl;
	std::cout << "Cows: " << Count.Cows << std::endl;
}

//=========================================================================================================================
/*
* Starts the game and is also called when player wishes to play again
*/
//=========================================================================================================================

void StartGame()
{
	// TODO - Create random string generator for Isotope
	std::string Isotope = "???";
	std::string Guess = GetGuess();

	std::cout << "Guess the " << Isotope.length() << " letter isotope...\n" << std::endl;

	// while game is NOT over (main game loop)
	// keep receiving guess input from user
	while (!(Game.IsGameOver))
	{
		// Is the guess valid?
		CheckGuess(Guess, Isotope);

		// Obviously not won, so decrement lives
		Game.DecrementLives();

		if (Game.GetLives() == 0)
		{
			Game.IsGameOver = true;

			std::cout << "\nGame Over! Would you like to play again (yes/no)?" << std::endl;

			std::string choice;
			std::cin >> choice;

			if (choice == "yes")
				StartGame();
			else if (choice == "no")
				std::cout << "Thank you for playing!\n";
			else
				Error("Error: Bad input!");

		}
	}

}

//=========================================================================================================================
/*
* main() starts off the game
*/
//=========================================================================================================================

int main()
try
{
	// Welcome note to user
	std::cout << "\t\t\t\t\t======================\n\t\t\t\t\t    Bulls and Cows\n\t\t\t\t\t======================\n";

	StartGame();

	return 0;
}
catch (std::runtime_error& E)
{
	std::cerr << "runtime error: " << E.what() << std::endl;
	return 1; // indicates failure
}

//=========================================================================================================================