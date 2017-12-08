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
	void drawDefaults();
	Dot *dot(int xCord, int yCord);
private:
	void setup(int width, int height);
public:
	int spacing = 10;
	int dotSize = 15;

	struct coordinate {
		int x = 0;
		int y = 0;
	} gridOffset;

	colorTemplate color;
	
	int _gridLengthInDots;
	int _gridHeightInDots;

	Dot *Origo = nullptr;
	Dot *LastDot = nullptr;
};

