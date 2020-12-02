#ifndef BISHOP
#define BISHOP

#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const bool white) :Piece(white) {}

	bool movePiece(const int xStart, const int yStart,
		const int xEnd, const int yEnd, Piece*** board);
	string getBoardString();
};

#endif // !BISHOP