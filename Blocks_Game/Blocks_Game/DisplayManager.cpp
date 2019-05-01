#include "pch.h"
#include "DisplayManager.h"
#include <iostream>


DisplayManager::DisplayManager()
{
}


DisplayManager::~DisplayManager()
{
}

void DisplayManager::Init()
{
	mainWindow = SDL_CreateWindow("Blocks", 50, 50, 540, 540, 0);
	mainRend = SDL_CreateRenderer(mainWindow, -1, 0);
	SDL_SetRenderDrawColor(mainRend, 0, 0, 255, 255); // can ignore
	isRunning = true;

	setupShapes();

	//initiliase grid i guess
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			grid[x][y] = 0;
		}
	}

}

void DisplayManager::RenderGame()
{
	SDL_SetRenderDrawColor(mainRend, 0, 0, 0, 255); // background colour
	SDL_RenderClear(mainRend);
	// draw time :D

	// make individual functions to draw these:
	//	OUTLINE GRID
	SDL_SetRenderDrawColor(mainRend, 255, 255, 255, 255);
	SDL_RenderDrawRect(mainRend, &gridOutline); // ---------- OUTLINE DONE ----------

	//	CURRENTLY PLACED BLOCKS
	SDL_Rect tempGridRects;
	tempGridRects.w = 50;
	tempGridRects.h = 50;
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			int gridPoint = grid[x][y];
			if (gridPoint != 0)
			{
				if (gridPoint == 1)
					SDL_SetRenderDrawColor(mainRend, 0, 255, 0, 255);
				else if (gridPoint == 2)
					SDL_SetRenderDrawColor(mainRend, 255, 255, 0, 255);
				else if (gridPoint == 3)
					SDL_SetRenderDrawColor(mainRend, 255, 0, 0, 255);
				else
					isRunning = false;

				tempGridRects.x = 70 + (x * 50);
				tempGridRects.y = 120 + (y * 50);

				SDL_RenderFillRect(mainRend, &tempGridRects);
			}
		}
	}


	//	BLOCK UR CURRENTLY PLACING
	SDL_SetRenderDrawColor(mainRend, 0, 0, 255, 64); 
	SDL_RenderFillRect(mainRend, &rekt);
	for (int i = 0; i < subRectsToRender; i++)
	{
		SDL_RenderFillRect(mainRend, &subrekts[i]);
	}

	//	TIMER
	SDL_SetRenderDrawColor(mainRend, 255, 255, 255, 255);
	SDL_RenderDrawRect(mainRend, &bigTimerBox);

	for (int i = 0; i < visibleBlips; i++)
	{
		SDL_RenderFillRect(mainRend, &smallTimerSquares[i]);
		SDL_RenderFillRect(mainRend, &smallTimerRects[i]);
	} // ---------- TIMER DONE ----------

	//	SCORE
	//	ANYTHING ELSE I THINK OF LATER

	// end draw time
	SDL_RenderPresent(mainRend);
}

void DisplayManager::Events()
{
	SDL_Event event;

	std::string updates = IO.update(); // get all data from arduino

	if (updates == "") updates = "0000-0000-0000-0"; // error check

	// split all data into strings (thus the random names)
	std::string s1 = updates.substr(0,4);
	std::string s2 = updates.substr(5, 4);
	std::string rt = updates.substr(10, 4);
	std::string bt = updates.substr(15, 1);

	// convert all that too reasonable data types;
	int sliderOneRaw = std::stoi(s1);
	int sliderTwoRaw = std::stoi(s2);
	int encoderRotations = std::stoi(rt);
	
	// // check for button press change

	bt == "1" ? buttonNow = true : buttonNow = false;

	bool diffCheck;
	buttonNow != buttonPrior ? diffCheck = true : diffCheck = false;

	if (diffCheck)
	{
		if (buttonNow)
		{
			buttonPressed = true;
		}
	}
	
	buttonPrior = buttonNow;


	// bound the sliders to the grid segments
	int sliderOneSegment = 0;
	while (sliderOneRaw > 127)
	{
		sliderOneRaw -= 128;
		sliderOneSegment++;
	}
	int sliderTwoSegment = 0;
	while (sliderTwoRaw > 127)
	{
		sliderTwoRaw -= 128;
		sliderTwoSegment++;
	}

	// lock the box to the bounds

	if (sliderOneSegment > (7 - xMax))
		sliderOneSegment = (7 - xMax);
	else if (sliderOneSegment < -xMin)
		sliderOneSegment = -xMin;

	if (sliderTwoSegment > (7 - yMax))
		sliderTwoSegment = (7 - yMax);
	else if (sliderTwoSegment < -yMin)
		sliderTwoSegment = -yMin;

	// finally, move the shape :D
	rekt.x = 70 + (sliderOneSegment* 50);
	rekt.y = 120 + (sliderTwoSegment * 50);
	

	if (buttonPressed)
	{
		TurnEnd();
	}

	buttonPressed = false;


	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_RIGHT)
			{
				rotateCW();
			}
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				rotateCCW();
			}
			break;
		default:
			break;
		}
	}
}

void DisplayManager::setupShapes()
{
	rekt.x = 70; // center cube
	rekt.y = 120;
	rekt.w = 50;
	rekt.h = 50;
	UpdateBlock();

	gridOutline.x = 69; // outline grid
	gridOutline.y = 119;
	gridOutline.w = 402;
	gridOutline.h = 402;
	
	bigTimerBox.x = 240; // timer box
	bigTimerBox.y = 20;
	bigTimerBox.w = 60;
	bigTimerBox.h = 60;

	// I have a really long comples (but cool looking') timer im boutta put in here
	int xoff = 239;
	int yoff = 19;


	int timerSquares[8][2] = { {18,4},{4,18},{4,33},{18,47},
								{33,47},{47,33},{47,18},{33,4} };

	for (int i = 0; i < smallTimerSquares.size(); i++)
	{
		smallTimerSquares[i].x = xoff + timerSquares[i][0];
		smallTimerSquares[i].y = yoff + timerSquares[i][1];
		smallTimerSquares[i].w = 11;
		smallTimerSquares[i].h = 11;
	}

	int timerRects[8][4] = { {24,15,5,8},{15,24,8,5},
							{15,33,8,5},{24,39,5,8},
							{33,39,5,8},{39,33,8,5},
							{39,24,8,5},{33,15,5,8} };

	for (int i = 0; i < smallTimerRects.size(); i++)
	{
		smallTimerRects[i].x = xoff + timerRects[i][0];
		smallTimerRects[i].y = yoff + timerRects[i][1];
		smallTimerRects[i].w = timerRects[i][2];
		smallTimerRects[i].h = timerRects[i][3];
	}
	// timer all set up woo, ***not rendered here***


}

void DisplayManager::NextBlip()
{
	visibleBlips--;
	if (visibleBlips == 0)
	{
		visibleBlips = 8;
		TurnEnd();
		subrekts.empty();
		//TODO: Trigger event to signify forced end of turn
	}
}

void DisplayManager::UpdateBlock()
{
	xMax = 0;
	xMin = 0;
	yMax = 0;
	yMin = 0;
	subRectsToRender = 0;
	if (rotation == North)
	{
		for (int i = 0; i < 8; i++)
		{
			shapePart currentPiece = cShape.pieces[i];
			if (!currentPiece.isEmpty())
			{
				subrekts[i].x = rekt.x + (50 * currentPiece.x);
				subrekts[i].y = rekt.y + (50 * currentPiece.y);
				subrekts[i].w = 50;
				subrekts[i].h = 50;
				subRectsToRender++;

				if (currentPiece.x > xMax)
					xMax = currentPiece.x;
				else if (currentPiece.x < xMin)
					xMin = currentPiece.x;

				if (currentPiece.y > yMax)
					yMax = currentPiece.y;
				else if (currentPiece.y < yMin)
					yMin = currentPiece.y;
			}
		}
	}
}

void DisplayManager::NewShape()
{
	cShape = SHandler.GetRandomShape();
}


void DisplayManager::TurnEnd()
{
	int grid_X = (rekt.x - 70) / 50;
	int grid_Y = (rekt.y - 120) / 50;


	//place piece
	grid[grid_X][grid_Y]++;
	for (int i = 0; i < 8; i++)
	{
		shapePart currentPiece = cShape.pieces[i];
		if (!currentPiece.isEmpty())
		{
			grid[grid_X + currentPiece.x][grid_Y + currentPiece.y]++;
		}
	}

	// now do the bigggg array checks
	// horizontal(?) checks

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (grid[x][y] == 0)
				break;
			else if (grid[x][y] > 0 && y == 7)
				scoreLine(x, -1);
		}
	}

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (grid[x][y] == 0)
				break;
			else if (grid[x][y] > 0 && x == 7)
				scoreLine(-1, y);
		}
	}


	multiplier = 1;
	visibleBlips = 8;
	NewShape();
	UpdateBlock();
	std::cout << score << std::endl;
}

void DisplayManager::scoreLine(int x, int y)
{
	if (x == -1) // the -1 recieved here means that the 'y' value is consitant
	{
		for (int q = 0; q < 8; q++)
		{
			grid[q][y]--;
		}
	}
	else
	{
		for (int q = 0; q < 8; q++)
		{
			grid[x][q]--;
		}
	}
	score += 100 * multiplier;
	multiplier++;
}

void DisplayManager::rotateCW()
{
	for (int i = 0; i < 8; i++)
	{
		shapePart* currentPiece = &cShape.pieces[i];
		if (!currentPiece->isEmpty())
		{
			int oldX = currentPiece->x;
			int oldY = currentPiece->y;

			currentPiece->x = -oldY;
			currentPiece->y = oldX;
		}
	}
	UpdateBlock();
}

void DisplayManager::rotateCCW()
{
	for (int i = 0; i < 8; i++)
	{
		shapePart *currentPiece = &cShape.pieces[i];
		if (!currentPiece->isEmpty())
		{
			int oldX = currentPiece->x;
			int oldY = currentPiece->y;

			currentPiece->x = oldY;
			currentPiece->y = -oldX;
		}
	}
	UpdateBlock();
}