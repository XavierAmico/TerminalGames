#pragma once
class tictactoe
{
private:
	char moves[3][3];  // it is your 3 by 3 board
	bool xturn;        // shows whose turn it is (True-> X ; False -> O)
    int xcount;
public:
	//should initialize whose turn it is and the moves array with empty spaces
	tictactoe();

	//should place an X or O, based on whose turn it is, at location x,y in the moves array
	// make sure the move is correct meaning it is in the board range and also the place is not already occupied
	// update the turn : If it was X turn, now it is O turn
	bool PlaceMove(int x, int y);

	
	
	
	
	
	/*draws the board using the moves 2d array. At first it should look like this	 
	      0   1   2
		0    |   |
		---------- -
		1    |   |
		---------- -
		2    |   |
		*/
	void DrawBoard();

	//should return true if there are 3 X's or 3 O's in a row or in diagonal ; also return true if the board is full 
	bool GameOver();


	//should return X or O ; the winner is usually the one who made the last move. If no body won, and the board is full, return the last person who made a move
	char Winner();
	


};

