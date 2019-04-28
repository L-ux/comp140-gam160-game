#pragma once
#include "SDL.h"
#include <array>
#include "ShapeHandler.h"
#include "Constants.h"
#include "IOHandler.h"

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
	void TurnEnd();
	bool CheckRunning() { return isRunning; }

private:
	SDL_Window* mainWindow;
	SDL_Renderer* mainRend;
	ShapeHandler SHandler;
	IOHandler IO;

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
	Shape cShape;
	SDL_Rect rekt;
	std::array<SDL_Rect, 8> subrekts;
	SDL_Rect gridOutline;
	SDL_Rect bigTimerBox;
	std::array<SDL_Rect, 8> smallTimerSquares;
	std::array<SDL_Rect, 8> smallTimerRects;

	int grid[8][8][3];
};

