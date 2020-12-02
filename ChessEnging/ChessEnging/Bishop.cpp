#include "Bishop.h"


bool Bishop::movePiece(const int xStart, const int yStart, const int xEnd, const int yEnd, Piece*** board)
{
	// If the end position is off the board just stop
	if (xEnd > 7 || xEnd < 0 || yEnd > 7 || yEnd < 0)
	{
		cerr << "Off of the board" << endl;
		return false;
	}

	// Bishops can move diagnol
	if (abs(xStart - xEnd) != abs(yStart - yEnd))
	{
		cerr << "Not on a diagnol" << endl;
		return false;
	}

	// Ensure that our end position is not taken by a same team piece
	if (board[xEnd][yEnd] != NULL)
	{
		if (board[xStart][yStart]->getIsWhite() == board[xEnd][yEnd]->getIsWhite())
		{
			cerr << "Position is taken by teammember" << endl;
			return false;
		}
	}
	
	int distance = abs(xStart - xEnd);

	if (distance == 0)
	{
		cerr << "Must move your piece" << endl;
		return false;
	}

	// If we are moving left
	if (yStart - yEnd > 0)
	{
		// If we are moving up
		if (xStart - xEnd > 0)
		{
			for (int i = 1; i < distance; i++)
			{
				if (board[xStart - i][yStart - i] != NULL)
				{
					cerr << "There is a piece in the way" << endl;
					cerr << "Moving up-left" << endl;
					cerr << "I: " << i << endl;
					return false;
				}
			}
		}
		// If we are moving down
		else
		{
			for (int i = 1; i < distance; i++)
			{
				if (board[xStart + i][yStart - i] != NULL)
				{
					cerr << "There is a piece in the way" << endl;
					cerr << "Moving down-left" << endl;
					cerr << "I: " << i << endl;
					return false;
				}
			}
		}
	}
	else
	{
		// If we are moving up
		if (xStart - xEnd > 0)
		{
			for (int i = 1; i < distance; i++)
			{
				if (board[xStart - i][yStart + i] != NULL)
				{
					cerr << "There is a piece in the way" << endl;
					cerr << "Moving up-right" << endl;
					cerr << "I: " << i << endl;
					return false;
				}
			}
		}
		// If we are moving down
		else
		{
			for (int i = 1; i < distance; i++)
			{
				if (board[xStart + i][yStart + i] != NULL)
				{
					cerr << "There is a piece in the way" << endl;
					cerr << "Moving down-right" << endl;
					cerr << "I: " << i << endl;
					return false;
				}
			}
		}
	}

	return true;
}

string Bishop::getBoardString()
{
	if (isWhite)
	{
		return "wb";
	}
	else
	{
		return "bb";
	}
}
