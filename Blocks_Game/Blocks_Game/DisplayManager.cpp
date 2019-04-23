#include "pch.h"
#include "DisplayManager.h"


DisplayManager::DisplayManager()
{
}


DisplayManager::~DisplayManager()
{
}

void DisplayManager::init()
{
	mainWindow = SDL_CreateWindow("Blocks", 50, 50, 720, 720, 0);
	mainRend = SDL_CreateRenderer(mainWindow, -1, 0);
	SDL_SetRenderDrawColor(mainRend, 0, 0, 255, 255);
	
	isRunning = true;
}

void DisplayManager::render()
{
	SDL_SetRenderDrawColor(mainRend, 0, 0, 255, 255);
	SDL_RenderClear(mainRend);

	// draw time
	
	// make individual functions to draw these:
	//	OUTLINE GRID
	//	CURRENTLY PLACED BLOCKS
	//	BLOCK UR CURRENTLY PLACING
	//	TIMER
	//	SCORE
	//	ANYTHING ELSE I THINK OF LATER

	// end draw time
	SDL_RenderPresent(mainRend);
}
