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
	void nextBlip();
	bool checkRunning() { return isRunning; }

private:
	SDL_Window* mainWindow;
	SDL_Renderer* mainRend;
	bool isRunning;
	int visibleBlips = 7;


	void setupShapes();
	SDL_Rect rekt;
	SDL_Rect gridOutline;
	SDL_Rect bigTimerBox;
	std::array<SDL_Rect, 8> smallTimerSquares;
	std::array<SDL_Rect, 8> smallTimerRects;
};

