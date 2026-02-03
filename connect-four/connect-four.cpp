

#include <string>
#include <iostream>
#include <vector>
#include "connect-four.h"


std::string red = "\033[38;5;196m";
std::string yellow = "\033[38;5;226m";
std::string reset = "\033[0m";

void connectFour::drawBoard() // This function will be called by takeTurn
{
	std::cout << "======================= Xavier's Connect 4 ======================" << std::endl;
	std::cout << "\t\t";
	for (int i = 0; i < 7; i++) {std::cout << "\033[36m" << "   " << i;}
	std::cout << reset << std::endl;

	bool boardnotFull = false;
	for (int i = 0; i < 6; i++) // i = row
	{
		std::cout << "\t\t";
		for (int j = 0; j < 7; j++ ) // j = column
		{
			std::cout << wall << chips[i][j];
		}
		std::cout << wall << std::endl;
	}
};

int connectFour::ask() // this private function will be called by place to get user input of where they'd like to place
{
	int column;
	std::string player = (redTurn) ? "Red" : "Yellow";
	std::string color = (redTurn) ? red : yellow;

	std::cout << color << player << "'s Turn (0-6): " << reset;
	while (!(std::cin >> column)) // Ensures input is an int
	{
		std::cout << "Invalid input! Please enter a valid number: ";

		std::cin.clear(); // Resets error flag
		std::cin.ignore(10000,'\n'); // discards bad stuff put into input
	}

	return column;

}
bool connectFour::place(int col)
{
	if (col > 6 || col < 0) {std::cout << "Out of bound, try again." << std::endl; return false;} // Entered a number out of bounds
	for (int i = 5; i >= 0; i--)
	{
		if (chips[i][col] == noChip)
		{
			chips[i][col] = (redTurn) ? redChip : yelChip;
			redTurn = !(redTurn);
			return true;
		}
	}
	std::cout << "Column is full, try again" << std::endl;
	return false; // col is full
}
void connectFour::takeTurn() // this function will call all other functions to allow for main to loop taking turn
{
	drawBoard();
	while (!place(ask())){}
}

bool connectFour::gameEnded()  // this will be used as the condition for the while loop in main 
{
	if (checkHorizontal() || checkVertical() || checkDiagonalLeft() || checkDiagonalRight())
	{
		std::string winner = (redWin) ? "Red" : "Yellow";
		drawBoard();

		std::cout << winner << " player wins!" << std::endl;
		std::cout <<"\nEnter any key to continue.." << std::endl;

		char exit;
		std::cin >> exit;
		return true;
	}
	bool tieGame = true;
	for (int i = 0; i < 6 && tieGame; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			tieGame = (chips[i][j] != noChip);
			if (!tieGame) {break;}
		}
	}
	return tieGame;
}

bool connectFour::checkHorizontal()
{
	int redStreak = 0;
	int yelStreak = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			std::string chip = chips[i][j];

			if (chip == noChip) {redStreak = 0; yelStreak = 0;}
		   else if (chip == redChip)  {redStreak++; yelStreak = 0;}
		   else if (chip == yelChip)  {yelStreak++; redStreak = 0;}

			if (redStreak >= 4)   {redWin = true; return true;}
		   else if (yelStreak >= 4)   {redWin = false; return true;}
		}

		redStreak = 0;
		yelStreak = 0;
	}
	return false;
}
bool connectFour::checkVertical()
{
	int redStreak = 0;
	int yelStreak = 0;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			std::string chip = chips[j][i];

			if (chip == noChip) {redStreak = 0; yelStreak = 0;}
		   else if (chip == redChip)  {redStreak++; yelStreak = 0;}
		   else if (chip == yelChip)  {yelStreak++; redStreak = 0;}

			if (redStreak >= 4)   {redWin = true; return true;}
		   else if (yelStreak >= 4)   {redWin = false; return true;}
		}

		redStreak = 0;
		yelStreak = 0;
	}
	return false;
}

bool connectFour::checkDiagonalLeft() // Top left to bottom right
{
	int redStreak = 0;
	int yelStreak = 0;

	for (int k = 0; k < 4; k++)
	{
		for (int i = 0, j = k; i < 6 && j < 7; i++, j++)
		{
			std::string chip = chips[i][j];

			if (chip == noChip) {redStreak = 0; yelStreak = 0;}
		   else if (chip == redChip)  {redStreak++; yelStreak = 0;}
		   else if (chip == yelChip)  {yelStreak++; redStreak = 0;}

			if (redStreak >= 4)   {redWin = true; return true;}
		   else if (yelStreak >= 4)   {redWin = false; return true;}

		}
		redStreak = 0;
		yelStreak = 0;
	}
	for (int k = 1; k < 3; k++)
	{
		for (int i = k, j = 0; i < 6 && j < 7; i++, j++)
		{
			std::string chip = chips[i][j];

			if (chip == noChip) {redStreak = 0; yelStreak = 0;}
		   else if (chip == redChip)  {redStreak++; yelStreak = 0;}
		   else if (chip == yelChip)  {yelStreak++; redStreak = 0;}

			if (redStreak >= 4)   {redWin = true; return true;}
		   else if (yelStreak >= 4)   {redWin = false; return true;}

		}
		redStreak = 0;
		yelStreak = 0;
	}
	return false;
}
bool connectFour::checkDiagonalRight() // Top right to bottom left
{
	int redStreak = 0;
	int yelStreak = 0;

	for (int k = 6; k >= 0; k--)
	{
		for (int i = 0, j = k; i < 6 && j >= 0; i++, j--)
		{
			std::string chip = chips[i][j];

			if (chip == noChip) {redStreak = 0; yelStreak = 0;}
		   else if (chip == redChip)  {redStreak++; yelStreak = 0;}
		   else if (chip == yelChip)  {yelStreak++; redStreak = 0;}

			if (redStreak >= 4)   {redWin = true; return true;}
		   else if (yelStreak >= 4)   {redWin = false; return true;}

		}
		redStreak = 0;
		yelStreak = 0;
	}
	for (int k = 2; k > 0; k--)
	{
		for (int i = k, j = 6; i < 6 && j >= 0; i++, j--)
		{
			std::string chip = chips[i][j];

			if (chip == noChip) {redStreak = 0; yelStreak = 0;}
		   else if (chip == redChip)  {redStreak++; yelStreak = 0;}
		   else if (chip == yelChip)  {yelStreak++; redStreak = 0;}

			if (redStreak >= 4)   {redWin = true; return true;}
		   else if (yelStreak >= 4)   {redWin = false; return true;}

		}
		redStreak = 0;
		yelStreak = 0;
	}
	return false;
}
