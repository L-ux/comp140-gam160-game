#include "pch.h"
#include <iostream>
#include "DisplayManager.h"
#include "IOHandler.h"

int main(int argc, char * argv[])
{
	DisplayManager DispMan;
	IOHandler IO;
	DispMan.init();
	while (true) { DispMan.render(); }
    std::cout << "Hello World!\n"; 
	std::cin;
	return 0;
}