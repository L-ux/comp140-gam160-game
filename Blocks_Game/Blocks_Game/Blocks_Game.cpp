#include "pch.h"
#include <iostream>
#include "DisplayManager.h"
#include "IOHandler.h"

int main(int argc, char * argv[])
{
	DisplayManager DispMan;
	IOHandler IO;
	DispMan.Init();
	while (DispMan.checkRunning())
	{
		int increment = SDL_GetTicks(); 
		if (increment % 1000 == 0) // every sec
		{
			std::cout << "BLIP!!!!" << std::endl;
			DispMan.NextBlip();
		}
		if (increment % 20 == 0) // 25 FPS
		{
			DispMan.Events();
			DispMan.Render();
		}
		
	}
	return 0;
}