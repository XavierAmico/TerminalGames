
#include "wordle.h"
#include <string>
#include <ctime>
#include <fstream>
#include <iostream>


Wordle::Wordle()
{
	std::srand(std::time(nullptr)); // Seed random

	// filling vector with all the words
	std::string word;
	std::ifstream wordFile("words.txt");

	while(getline(wordFile, word))
	{
		words.push_back(word);
	}
}

void Wordle::gameMgr()
{
	selectWord();
	std::cout << "Correct Word:" << curWord << std::endl; 
	while(!gameWin)
	{
		generateOutput(askUser());
	}
	std::cout << "Congratulations! The word was " << curWord << "! You did it" << std::endl;
}

void Wordle::generateOutput(std::string guess)
{
	output.clear();
	for (int i = 0; i < 5; i++)
	{
		output.push_back(colorLetter((char)guess[i],i)); // Colors each letter accordingly
	}

	for (std::string s : output)
	{
		std::cout << s << " " << reset;
	}
	std::cout << std::endl;
}

void Wordle::startGame()
{
	std::cout << "\t=== Welcome to Xavier's Wordle ===" << std::endl;

	std::cout << green << "\tCorrect" << yellow << "   Contains" << reset << "   Nope" << std::endl;
	gameMgr();
}

std::string Wordle::askUser()
{
	std::string guess;
	bool isValid = false;

	while (!isValid)
	{
		std::cout << "\nEnter a guess:" << std::endl;
		std::cin >> guess;
		if (guess.length() != 5)
		{
			std::cout << "Word must be five letters, please try again" << std::endl;
		}
		else if(!search(guess))
		{
			std::cout << "Word is not in word list, please try again" << std::endl;
		}
		else if(guess == curWord)
		{
			gameWin = true;
		}
		else
		{
			isValid = true;
		}
	}

	return guess;
}

void Wordle::selectWord()
{
	int ranNum = std::rand() % words.size(); // chooses a random index in words
	curWord = words[ranNum];
}

bool Wordle::search(std::string input)
{
	int low = 0;
	int high = words.size()-1;
	int mid = (high - low) / 2;
	while(low <= high)
	{
		if (input == words[mid]) 	{return true;} // word found in word list
		else if (input < words[mid])	{high = mid-1;}
		else if (input > words[mid])	{low = mid+1;}
		mid = ((high - low) / 2) + low;
	}
	// Case word is not in word list
	return false;

}

std::string Wordle::colorLetter(char ltr, int index)
{
	std::string newString(1,ltr);

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Before if: " << newString << std::endl;
		if(ltr == curWord[i]) // Letter is in the word
		{
			newString = (i == index) ? green + newString : yellow + newString;
			newString += reset;
			std::cout << "After if: " << newString << std::endl;
			break;									 // if at correct spot, green else yellow
		}
	}
	return newString;
}

