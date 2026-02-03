
// Xavier Amico

#include "tictactoe.h"
#include <iostream>

using namespace std;

tictactoe::tictactoe()
{
	// ************* TO DO*******************
    cout << "Welcome to Xavier's tictactoe game! It is the X's turn to place first.\n";
    
    xturn = true; 
    xcount = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            moves[i][j] = ' ';
        }
    }
}


bool tictactoe::PlaceMove(int x, int y)
{
	// ************* TO DO*******************
	if ((x < 3 && x >= 0) && (y < 3 && y >= 0) && (moves[x][y] == ' '))
	{
	    if (xturn)
	    {
	        moves[x][y] = 'X';
	        xturn = 0;
	        xcount++; // ADDED THIS VARIABLE TO DETERMINE IF BOARD IS FULL, IT IS IN THE HEADER 
	    }
	    else
	    {
	        moves[x][y] = 'O';
	        xturn = 1;
	    }
	    return true;
	}
	
	if (moves[x][y] != ' ')
	{
	    cout << "Invalid Move, the placement needs to be an empty square. \n";
	}
	else
	{
	    cout << "Invalid Move, make sure you are within range(0-2). \n";
	}
	return false; 
}

void tictactoe::DrawBoard()
{
	// ************* TO DO*******************
	cout << "  0   1   2" << endl
	     << "0 " << moves[0][0] << " | " << moves[0][1] << " | " << moves[0][2] << endl
	     << "---------- -"                                                     << endl
	     << "1 " << moves[1][0] << " | " << moves[1][1] << " | " << moves[1][2] << endl
	     << "---------- -"                                                     << endl
	     << "2 " << moves[2][0] << " | " << moves[2][1] << " | " << moves[2][2] << endl
	     << endl;
}


bool tictactoe::GameOver()
{
	// ************* TO DO*******************
    for (int i = 0; i < 3; i++) 
    {
        
        // Columns & Rows
        if (moves[i][0] != ' ' && moves[i][0] == moves[i][1] && moves[i][1] == moves[i][2])
        {
            return true;
        }
        if (moves[0][i] != ' ' && moves[0][i] == moves[1][i] && moves[1][i] == moves[2][i])
        {
            return true; 
        }
        
        // Diagonal Checks
        if (moves[0][0] != ' ' && moves[0][0] == moves[1][1] && moves[1][1] == moves[2][2])
        {
            return true; 
        }
        if (moves[2][0] != ' ' && moves[2][0] == moves[1][1] && moves[1][1] == moves[0][2])
        {
            return true;
        }
        
        // Game Board FULL
        if (xcount >= 5)
        {
            xcount = -1; // Using this to differentiate the output message between x winning on turn 9, and a tie. 
            return true;
        }
    } 
    return false; 
}

char tictactoe::Winner()
{
	// ************* TO DO*******************
	if (xcount == -1)
	{
	    cout << "Ended in a tie, no one";
	    return ' ';
	}
	if (!xturn)
	{
	    return 'X';
	}
	    
	return 'O';
}
