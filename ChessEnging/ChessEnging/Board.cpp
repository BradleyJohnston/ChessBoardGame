#include "Board.h"

#define WHITE true
#define BLACK false

void Board::resetBoard()
{
	cerr << "ResetBoard start" << endl;
	
	if (board)
	{
		// Clear array
		for (int i = 0; i < 8; i++)
		{
			delete this->board[i];
		}
		delete[]this->board;
	}

	// Create the 8 rows
	this->board = new Piece ** [8];
	
	// Create the 8 collumns
	for (int i = 0; i < 8; i++)
	{
		board[i] = new Piece * [8];
	}

	// Initialize each square to something
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = NULL;
		}
	}

	// Bottom Row White pieces
	board[7][0] = new Rook(WHITE);
	board[7][1] = new Knight(WHITE);
	board[7][2] = new Bishop(WHITE);
	board[7][3] = new Queen(WHITE);
	board[7][4] = new King(WHITE);
	board[7][5] = new Bishop(WHITE);
	board[7][6] = new Knight(WHITE);
	board[7][7] = new Rook(WHITE);

	// White/Black pawns
	for (int i = 0; i < 8; i++)
	{
		board[6][i] = new Pawn(WHITE);
		board[1][i] = new Pawn(BLACK);
	}

	// Top Row Black pieces
	board[0][0] = new Rook(BLACK);
	board[0][1] = new Knight(BLACK);
	board[0][2] = new Bishop(BLACK);
	board[0][3] = new Queen(BLACK);
	board[0][4] = new King(BLACK);
	board[0][5] = new Bishop(BLACK);
	board[0][6] = new Knight(BLACK);
	board[0][7] = new Rook(BLACK);
}

void Board::displayBoard()
{
	for (int i = 0; i < 8; i++)
	{
		cout << "   +----+----+----+----+----+----+----+----+" << endl;
		cout << " " << 8 - i << setw(3) << "| ";
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == NULL)
			{
				cout << "   | ";
			}
			else
			{
				cout << board[i][j]->getBoardString() << " | ";
			}
		}
		cout << endl;
	}
	cout << "   +----+----+----+----+----+----+----+----+" << endl;
	cout << "     A    B    C    D    E    F    G    H" << endl << endl;
	
}

void Board::movePiece()
{
	// Initialize some values
	int startX = 0;
	int startY = 0;

	int endX = 0;
	int endY = 0;

	string buffer;

	// Get piece to move
	cout << "What piece to move? (Ex: A1, C7, etc.)";
	cin >> buffer;

	// ASCII conversion
	startY = (int)buffer[0] - 65;
	startX = 7 - ((int)buffer[1] - 49);

	// Get position to move it to
	cout << "Where to move it to? (Ex: A1, C7, etc.)";
	cin >> buffer;

	// ASCII conversion
	endY = (int)buffer[0] - 65;
	endX = 7 - ((int)buffer[1] - 49);

	cerr << "X:Y, " << startX << startY << endl;
	cerr << "X:Y, " << endX << endY << endl;

	// Test if move is a valid move for that piece
	if (board[startX][startY] == NULL)
	{
		cout << "Invalid Piece" << endl;
		return;
	}
	if ( board[startX][startY]->movePiece(startX, startY, endX, endY, this->board)
		&& board[startX][startY]->getIsWhite() == isWhiteTurn)
	{

		// If it is valid move the pieces
		board[startX][startY]->setCanCastleFalse();
		board[endX][endY] = board[startX][startY];
		board[startX][startY] = NULL;

		if (PreviousPawn)
		{
			PreviousPawn->resetEmpassant();
			PreviousPawn = NULL;
		}
		
		if (board[endX][endY]->getBoardString()[1] == 'p')
		{
			PreviousPawn = board[endX][endY];
		}

		cerr << "Previous piece empassantable: " << board[endX][endY]->getEmpassant() << endl;
		isWhiteTurn = !isWhiteTurn;
	}
	else
	{
		cout << "Invalid move" << endl;
	}
}
