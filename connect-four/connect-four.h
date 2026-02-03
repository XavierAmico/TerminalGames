#include <iostream>
#include <vector>

class connectFour
{
	public:
	void takeTurn();
	bool gameEnded();

	private:

	void drawBoard();
	int ask();
	bool place(int col);

	bool checkHorizontal(); // helper func for game ended
	bool checkVertical(); // helper func for game ended
	bool checkDiagonalLeft(); // helper func for game ended 
	bool checkDiagonalRight(); //i mean yeah helper func 

	bool redWin = false;
	bool redTurn = true;
	std::string wall = " | "; // Draws the board walls
	std::string noChip  = "O";
	std::string redChip = "\033[38;5;196mO\033[0m"; // Print out "O" in red
	std::string yelChip = "\033[38;5;226mO\033[0m"; // Prints out "O" in yellow
	std::vector<std::vector<std::string>> chips{6, std::vector<std::string>(7, noChip)}; // Fills the board with blank white chips
};
