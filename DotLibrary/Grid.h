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
	Dot *Origo = nullptr;
	Dot *LastDot = nullptr;
public:
	int spacing = 10;
	int dotSize = 15;

	coordinateTemplate offset;

	colorTemplate color;
	
	const int _gridLengthInDots;
	const int _gridHeightInDots;
};

