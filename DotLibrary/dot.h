#pragma once
#include <string>
#include "Window.h"
#include "Definitions.h"

using namespace std;

class Dot {
private:
	Dot(int xPos, int yPos);
	~Dot();
public:
	void draw();
	
public:
	friend class Grid;
	friend class Text;

	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;

	colorTemplate color;
	sizeTemplate size;
	coordinateTemplate screenCoordinates;
	const coordinateTemplate coordinates = *_coordinates;

private:
	coordinateTemplate* _coordinates;
};

