#pragma once
#include "SDL.h"
#include <array>
#include "ShapeHandler.h"
#include "Constants.h"

class DisplayManager
{
public:
	DisplayManager();
	~DisplayManager();

	void Init();
	void RenderGame();
	void Events();
	void NextBlip();
	void UpdateBlock();
	bool CheckRunning() { return isRunning; }

private:
	SDL_Window* mainWindow;
	SDL_Renderer* mainRend;
	ShapeHandler SHandler;

	bool isRunning;

	int visibleBlips = 7;
	int subRectsToRender;

	double fRotation;
	double fSliderH;
	double fSliderV;
	enum compassRotation
	{
		North, //default
		East,
		South,
		West
	};
	compassRotation rotation = North;

	void setupShapes();
	SDL_Rect rekt;
	std::array<SDL_Rect, 8> subrekts;
	SDL_Rect gridOutline;
	SDL_Rect bigTimerBox;
	std::array<SDL_Rect, 8> smallTimerSquares;
	std::array<SDL_Rect, 8> smallTimerRects;
};

