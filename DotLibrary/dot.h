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
	// Get commands
	inline colorTemplate getColor() { return(_color); };
	inline sizeTemplate getSize() { return(_size); };
	inline coordinateTemplate getCoords() { return(_coordinates); };
	inline coordinateTemplate getScreenCoords() { return(_screenCoordinates); };
	// Set commands
	inline void setColor(int r, int g, int b) { _color.r = r, _color.g = g, _color.b = b; };
	inline void setSize(int width, int height) { _size.w = width, _size.h = height; };

private:
	friend class Grid;
	friend class Text;

	colorTemplate _color;
	sizeTemplate _size;
	coordinateTemplate _coordinates;
	coordinateTemplate _screenCoordinates;

	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;
};

