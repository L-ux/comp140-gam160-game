#pragma once
#include "SDL.h"
#include <array>

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();

	void Init();
	void Render();
	void Events();
	void NextBlip();
	bool checkRunning() { return isRunning; }

private:
	SDL_Window* mainWindow;
	SDL_Renderer* mainRend;
	bool isRunning;
	int visibleBlips = 4;


	void setupShapes();
	SDL_Rect rekt;
	SDL_Rect gridOutline;
	SDL_Rect bigTimerBox;
	std::array<SDL_Rect, 5> smallTimerBoxes;
};

