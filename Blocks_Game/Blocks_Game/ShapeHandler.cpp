#include "pch.h"
#include "ShapeHandler.h"


ShapeHandler::ShapeHandler()
{
	// this is gonna be very ugly, but its the creation of all the pieces so of course its not gonna be pretty :P


	/* Piece 1

		O
	*/
	shapePart pieceOne[8] = { EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,
								EMPTYPIECE, EMPTYPIECE, EMPTYPIECE, EMPTYPIECE };
	allShapes[0].setPieces(pieceOne, 8);

	/* Piece 2

		O X
	*/
	shapePart pieceTwo[8] = { shapePart(1,0),EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,
							EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE };
	allShapes[1].setPieces(pieceTwo, 8);

	/* Piece 3

		X O X
	*/
	shapePart pieceThree[8] = { shapePart(1,0), shapePart(-1,0),EMPTYPIECE,EMPTYPIECE,
							EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE };
	allShapes[2].setPieces(pieceThree, 8);

	/* Piece 4

	X O X X
	*/
	shapePart pieceFour[8] = { shapePart(1,0), shapePart(2,0), shapePart(-1,0),EMPTYPIECE,
							EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE };
	allShapes[3].setPieces(pieceFour, 8);

	/* Piece 5

	X X O X X
	*/
	shapePart pieceFive[8] = { shapePart(1,0), shapePart(2,0), shapePart(-1,0), shapePart(-2, 0),
							EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE };
	allShapes[4].setPieces(pieceFive, 8);

	/* Piece 6

	X
	O X
	*/
	shapePart pieceSix[8] = { shapePart(1,0), shapePart(0,-1), EMPTYPIECE, EMPTYPIECE,
							EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE };
	allShapes[5].setPieces(pieceSix, 8);

	/* Piece 7

		X
		X
		O X X
	*/
	shapePart pieceSeven[8] = { shapePart(1,0), shapePart(2,0), shapePart(0,-1), shapePart(0,-2),
							EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE };
	allShapes[6].setPieces(pieceSeven, 8);

	/* Piece 8

	X X
	O X
	*/
	shapePart pieceEight[8] = { shapePart(1,0), shapePart(0,-1), shapePart(1,-1), EMPTYPIECE,
							EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE };
	allShapes[7].setPieces(pieceEight, 8);

	/* Piece 9

	X X X
	X O X
	X X X
	*/
	shapePart pieceNine[8] = { shapePart(1,0), shapePart(1,1), shapePart(0,1), shapePart(-1,1),
							shapePart(-1,0), shapePart(-1,-1), shapePart(0,-1), {1, -1} };
	allShapes[8].setPieces(pieceNine, 8);

}


ShapeHandler::~ShapeHandler()
{
}
