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

void DisplayManager::Render()
{
	SDL_SetRenderDrawColor(mainRend, 0, 0, 0, 255); // background colour
	SDL_RenderClear(mainRend);

	// draw time

	// make individual functions to draw these:
	//	OUTLINE GRID
	SDL_SetRenderDrawColor(mainRend, 255, 255, 255, 255);
	SDL_RenderDrawRect(mainRend, &gridOutline);
	//	CURRENTLY PLACED BLOCKS
	//	BLOCK UR CURRENTLY PLACING
	//	TIMER
	SDL_RenderDrawRect(mainRend, &bigTimerBox);
	for (int i = 0; i < visibleBlips; i++)
	{
		SDL_RenderFillRect(mainRend, &smallTimerBoxes[i]);
	}
	//SDL_RenderDrawRects(mainRend, );
	//	SCORE
	//	ANYTHING ELSE I THINK OF LATER
	SDL_SetRenderDrawColor(mainRend, 0, 0, 255, 255);
	SDL_RenderFillRect(mainRend, &rekt);


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
	rekt.x = 70;
	rekt.y = 120;
	rekt.w = 50;
	rekt.h = 50;

	gridOutline.x = 69;
	gridOutline.y = 119;
	gridOutline.w = 402;
	gridOutline.h = 402;
	
	bigTimerBox.x = 240;
	bigTimerBox.y = 20;
	bigTimerBox.w = 60;
	bigTimerBox.h = 60;

	for (int i = 0; i < smallTimerBoxes.size(); i++)
	{
		smallTimerBoxes[i].x = 235 + (15 * i);
		smallTimerBoxes[i].y = 90;
		smallTimerBoxes[i].w = 10;
		smallTimerBoxes[i].h = 5;
	}

	

}

void DisplayManager::NextBlip()
{
	visibleBlips--;
	if (visibleBlips == 0)
	{
		visibleBlips = 5;
	}
	std::cout << visibleBlips << std::endl;
}