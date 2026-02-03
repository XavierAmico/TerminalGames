#include "rps.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <ctime>
#include <cstdlib>


std::string myUpper(std::string s) // found this codce on the web.. TODO: Move this to a file called myUtilities
{
	std::transform(s.begin(), s.end(), s.begin(),
	[](unsigned char c) {return std::toupper(c);});
	return s;

}

rps::rps()  {std::srand(std::time(nullptr));}

std::string rps::choose()
{
	int ranNum = std::rand()  % 3; // Chooses number between 0-2
	return choices[ranNum];
}

std::string rps::ask()
{
	std::string playerChoice;
	std::cout << "\nChoose rock, paper, or scissors (R, P, or S): ";
	std::cin >> playerChoice;

	playerChoice = myUpper(playerChoice); // Converts to Upper

	std::string validChoices[7] = {"ROCK", "PAPER", "SCISSORS", "R", "P", "S","EXIT"};
	bool isValid = false;

	for (int i = 0; i < 7; i++)
	{
		if (playerChoice == validChoices[i])
		{
			if (playerChoice == "R") {playerChoice = "ROCK";}
			if (playerChoice == "P") {playerChoice = "PAPER";}
			if (playerChoice == "S") {playerChoice = "SCISSORS";}
			return playerChoice;
		}
	}
	std::cout << "Please make a valid choice, or type 'exit'" << std::endl;
	return rps::ask();
}

int rps::checkifWin(std::string player, std::string bot)
{
	if (player == bot)
	{
		return 0;
	}
	// 0 is tie, 1 is player win, 2 is bot win 
	if (player == "ROCK")
	{
		if (bot == "SCISSORS") {return 1;}
		else {return 2;}

	}
	if (player == "PAPER")
	{
		if (bot == "ROCK") {return 1;}
		else {return 2;}

	}
	if (player == "SCISSORS")
	{
		if (bot == "PAPER") {return 1;}
		else {return 2;}
	}
}

