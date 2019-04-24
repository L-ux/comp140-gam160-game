#pragma once
#include "Shape.h"
#include <random>
#include "Constants.h"

class ShapeHandler
{
public:
	ShapeHandler();
	~ShapeHandler();

	Shape GetRandomShape() { return *allShapes[std::rand() % 9]; }

private:
	Shape* allShapes[9];
};

