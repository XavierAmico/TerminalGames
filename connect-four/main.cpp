#include "connect-four.h"


int main()
{
	connectFour game;
	while(!game.gameEnded()) {game.takeTurn();}

	return 0;

}
