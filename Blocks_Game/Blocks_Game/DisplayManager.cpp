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
}

void DisplayManager::RenderGame()
{
	SDL_SetRenderDrawColor(mainRend, 0, 0, 0, 255); // background colour
	SDL_RenderClear(mainRend);
	// draw time :D

	// make individual functions to draw these:
	//	OUTLINE GRID
	SDL_SetRenderDrawColor(mainRend, 255, 255, 255, 255);
	SDL_RenderDrawRect(mainRend, &gridOutline); // OUTLINE DONE

	//	CURRENTLY PLACED BLOCKS
	//	BLOCK UR CURRENTLY PLACING
	//	TIMER
	SDL_RenderDrawRect(mainRend, &bigTimerBox);

	for (int i = 0; i < visibleBlips; i++)
	{
		SDL_RenderFillRect(mainRend, &smallTimerSquares[i]);
		SDL_RenderFillRect(mainRend, &smallTimerRects[i]);
	} // TIMER DONE

	//	SCORE
	//	ANYTHING ELSE I THINK OF LATER
	SDL_SetRenderDrawColor(mainRend, 0, 0, 255, 255); // test cube
	SDL_RenderFillRect(mainRend, &rekt); // test cube


	// end draw time
	SDL_RenderPresent(mainRend);
}

void DisplayManager::Events()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_w)
			{
				rekt.y -= 50;
			}
			else if (event.key.keysym.sym == SDLK_s)
			{
				rekt.y += 50;
			}
			else if (event.key.keysym.sym == SDLK_a)
			{
				rekt.x -= 50;
			}
			else if (event.key.keysym.sym == SDLK_d)
			{
				rekt.x += 50;
			}
			break;
		default:
			break;
		}
	}
}

void DisplayManager::setupShapes()
{
	rekt.x = 70; // test cube
	rekt.y = 120;
	rekt.w = 50;
	rekt.h = 50;

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
		//TODO: Trigger event to signify forced end of turn
	}
}