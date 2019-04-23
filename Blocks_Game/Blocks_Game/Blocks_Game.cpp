#include "pch.h"
#include <iostream>
#include "DisplayManager.h"
#include "IOHandler.h"

const int TICKSPERSECOND = 1000; //1000 ticks per second, 
const int TIMERSTEPRATE = 125; // 8 blips in the timer, constant used to make turn time into a measure of ticks. 

int main(int argc, char * argv[])
{
	DisplayManager DispMan;
	IOHandler IO;
	DispMan.Init();
	int turnTime = 4; // turn time in seconds (roughly)
	int desiredFPS = 25; // desired FPS
	int lastRenderTime = 0; // may need to add an offset around here if i add a main menu.
	int lastTimerChange = 0;

	while (DispMan.checkRunning())
	{
		int increment = SDL_GetTicks(); 
		if (increment >= lastTimerChange + (turnTime * TIMERSTEPRATE)) // 4 time(s) every 3 sec
		{
			DispMan.nextBlip();
			lastTimerChange = increment;
		}
		if (increment >= lastRenderTime + (TICKSPERSECOND / desiredFPS)) // 25 FPS
		{
			DispMan.Events();
			DispMan.Render();
			lastRenderTime = increment;
		}
		
	}
	return 0;
}