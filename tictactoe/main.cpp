#include <iostream>
#include "tictactoe.h"

using namespace std;


int main()
{
	tictactoe board;
	int col, row;
	
	do
	{
		board.DrawBoard();
		cout << "Row: ";
		cin >> row;
		cout << "Col: ";
		cin >> col;

		if (!board.PlaceMove(row, col))
			cout << "Invalid Move" << endl;
	} while (!board.GameOver());

	board.DrawBoard();
	cout << board.Winner() << " wins!" << endl;


	return 0;
}
