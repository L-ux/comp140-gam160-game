#include "pch.h"
#include "ShapeHandler.h"


ShapeHandler::ShapeHandler()
{
	// this is gonna be very ugly, but its the creation of all the pieces so of course its not gonna be pretty :P


	/* Piece 1

		O
	*/
	int pieceOne[8][2] = { *EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,
							*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE };
	allShapes[0]->setPieces(pieceOne);

	/* Piece 2

		O X
	*/
	int pieceTwo[8][2] = { {1,0},*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,
							*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE };
	allShapes[1]->setPieces(pieceTwo);

	/* Piece 3

		X O X
	*/
	int pieceThree[8][2] = { {1,0}, {-1,0},*EMPTYPIECE,*EMPTYPIECE,
							*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE };
	allShapes[2]->setPieces(pieceThree);

	/* Piece 4

	X O X X
	*/
	int pieceFour[8][2] = { {1,0}, {2,0}, {-1,0},*EMPTYPIECE,
							*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE };
	allShapes[3]->setPieces(pieceFour);

	/* Piece 5

	X X O X X
	*/
	int pieceFive[8][2] = { {1,0}, {2,0}, {-1,0}, {-2, 0},
							*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE };
	allShapes[4]->setPieces(pieceFive);

	/* Piece 6

	X
	O X
	*/
	int pieceSix[8][2] = { {1,0}, {0,-1}, *EMPTYPIECE, *EMPTYPIECE,
							*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE };
	allShapes[5]->setPieces(pieceSix);

	/* Piece 7

		X
		X
		O X X
	*/
	int pieceSeven[8][2] = { {1,0}, {2,0}, {0,-1}, {0,-2},
							*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE };
	allShapes[6]->setPieces(pieceSeven);

	/* Piece 8

	X X
	O X
	*/
	int pieceEight[8][2] = { {1,0}, {0,-1}, {1,-1}, *EMPTYPIECE,
							*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE,*EMPTYPIECE };
	allShapes[7]->setPieces(pieceEight);

	/* Piece 9

	X X X
	X O X
	X X X
	*/
	int pieceNine[8][2] = { {1,0}, {1,1}, {0,1}, {-1,1},
							{-1,0}, {-1,-1}, {0,-1}, {1, -1} };
	allShapes[8]->setPieces(pieceNine);

}


ShapeHandler::~ShapeHandler()
{
}
