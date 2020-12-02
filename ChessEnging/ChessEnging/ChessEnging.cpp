// ChessEnging.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"

int main()
{


	Board board;
	board.displayBoard();

	while (true)
	{
		cout << "\n\n\n" << endl;
		board.movePiece();
		board.displayBoard();
	}
	return 0;
}

