#pragma once
#include "SDL.h"

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();

	void init();
	void render();

private:
	SDL_Window* mainWindow;
	SDL_Renderer* mainRend;
};

