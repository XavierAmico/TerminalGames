#include "rps.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

int main()
{
	const std::string red = "\033[1;31m";
    	const std::string green = "\033[1;32m";
	const std::string yellow ="\033[1;33m";
	const std::string blue = "\033[1;34m";
    	const std::string reset = "\033[0m";

	rps gamemgr;
	int wins = 0, loss = 0, ties = 0; 
	std::cout << blue  <<  "\n === Welcome to Xavier's Rock Paper Scissors Game! ===\n " << reset << std::endl;
	
	while(true)
	{
	std::string input = gamemgr.ask(); // Asks user for their guess and searches for exit
	
	if (input == "EXIT"){break;}
	
	std::string botChoice = gamemgr.choose();
	int gameState = gamemgr.checkifWin(input, botChoice);

	std::cout << "\n3.." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "2.." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "1..\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "You chose " << input << ", the bot chose " << botChoice << '\n' << std::endl;
	
	switch (gameState)
	{
		case 0: std::cout << yellow << "You tied"  << reset  << std::endl;  ties++; break;
		case 1: std::cout << green << "Player Wins" <<  reset << std::endl;  wins++; break;
		case 2: std::cout << red   << "Bot Wins"    <<  reset << std::endl;  loss++; break; 
	}

	std::cout << green << "Wins: " << wins << yellow  << " Ties: " << ties << red << " Losses: " << loss << reset << std::endl;

	}
	return 0;
}
