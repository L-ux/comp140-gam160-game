#pragma once
#include "Shape.h"
#include <random>
#include "Constants.h"

class ShapeHandler
{
public:
	ShapeHandler();
	~ShapeHandler();

	Shape GetRandomShape() 
	{ 
		int randNum = std::rand() % 9;
		return allShapes[randNum]; 
	}

private:
	Shape allShapes[9];
};

