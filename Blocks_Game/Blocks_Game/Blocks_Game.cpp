#include "pch.h"
#include <iostream>
#include "DisplayManager.h"
#include "Constants.h"
#include <random>

int main(int argc, char * argv[])
{
	DisplayManager DispMan;
	DispMan.Init();
	std::srand(SDL_GetTicks());
	int turnTime = 6; // turn time in seconds (roughly)
	int desiredFPS = 25; // desired FPS
	int lastRenderTime = 0; // may need to add an offset around here if i add a main menu.
	int lastTimerChange = 0;
	int ticksSinceStart = SDL_GetTicks(); // delay for main menu
	while (DispMan.CheckRunning())
	{

		int increment = SDL_GetTicks() - ticksSinceStart; 
		if (increment >= lastTimerChange + (turnTime * TIMERSTEPRATE)) // 4 time(s) every 3 sec
		{
			DispMan.NextBlip();
			lastTimerChange = increment;
		}
		if (increment >= lastRenderTime + (TICKSPERSECOND / desiredFPS)) // 25 FPS
		{
			DispMan.Events();
			//DispMan.RenderGame();
			lastRenderTime = increment;
		}
		
	}
	return 0;
}