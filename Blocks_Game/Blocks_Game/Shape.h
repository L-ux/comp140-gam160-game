#pragma once

struct Shape
{
public:
	int pieces[8][2];
	void setPieces(int set[8][2])
	{
		for (int x = 0; x < 8; x++)
		{
			for (int y = 0; y < 2; y++)
			{
				pieces[x][y] = set[x][y];
			}
		}
	}
};