#ifndef BOARD
#define BOARD

#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Board.h"


#include <list> // Linked List
#include <iostream> // displaying board
#include <iomanip> // polish
#include <string> // input helping

using namespace std;

class Board
{
private:
	// Containter for white pieces
	// A 2d array of Piece* holding the board state
	Piece*** board;
	Piece* PreviousPawn = NULL;
	bool isWhiteTurn;

public:
	// Methods
	void resetBoard();
	void displayBoard();
	void movePiece();

	Board() { this->resetBoard(); isWhiteTurn = true; }
};

#endif // !BOARD
