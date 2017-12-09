#pragma once
#include <string>
#include <iostream>
#include "Window.h"
#include "Dot.h"
#include "Definitions.h"

using namespace std;

class Grid {
public:
	Grid(int width, int height);
	~Grid();
	void visualize();
	//void Grid::SetupWindow(string title, int screenWidth, int screenHeight); 
	void drawDefaults();
	Dot *dot(int xCord, int yCord);
private:
	friend class Text;
	void setup(int width, int height);
public:
	// Get commands
	inline sizeTemplate getGridSize() { return(_gridSize); };
	inline coordinateTemplate getOffset() { return(_offset); };
	inline colorTemplate getColor() { return(_color); };
	inline int getSpacing() { return(_spacing); };
	inline int getDotSize() { return(_dotSize); };

	// Set commands
	inline void setOffset(int x, int y) { _offset.x = x, _offset.y = y; };
	inline void setColor(int r, int g, int b) { _color.r = r, _color.g = g, _color.b = b; };
	inline void setSpacing(int spacing) { _spacing = spacing; };
	inline void setDotSize(int dotSize) { _dotSize = dotSize; };
private:
	Dot *Origo = nullptr;
	Dot *LastDot = nullptr;
	sizeTemplate _gridSize;

	// Changeble variables
	int _spacing = 10;
	int _dotSize = 15;
	coordinateTemplate _offset;
	colorTemplate _color;
	
};

