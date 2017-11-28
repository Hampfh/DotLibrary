#pragma once
#include <string>
#include "Window.h"
#include "Definitions.h"

using namespace std;

class Dot {
public:
	Dot(int xPos, int yPos);
	~Dot();
	void draw();
	
public:

	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;

	colorTemplate color;
	sizeTemplate size;
	coordinateTemplate coordinates;
	coordinateTemplate screenCoordinates;
};

