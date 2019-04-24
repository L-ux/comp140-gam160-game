#pragma once

struct shapePart
{
public:
	int x;
	int y;
	shapePart() : x(0), y(0) {}
	shapePart(int a, int b) : x(a), y(b) {}
	bool isEmpty()
	{
		if (x == 0 && y == 0)
			return true;
		else
			return false;
	}
};

const shapePart EMPTYPIECE = shapePart(0, 0);

class Shape
{
public:
	shapePart pieces[8] = { EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE,EMPTYPIECE };


	void setPieces(shapePart *recievedPieces, int size)
	{
		//pieces[1] = EMPTYPIECE;

		//shapePart pcs[8] = recievedPtr;

		for (int i = 0; i < size; i++)
		{
			shapePart eh = recievedPieces[i];
			pieces[i] = eh;
		}
	}

};