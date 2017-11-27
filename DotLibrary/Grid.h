#pragma once
#include <string>
#include <iostream>
#include "Window.h"
#include "Dot.h"

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
	void setup(int width, int height);
public:

	int spacing = 10;
	int dotSize = 20;

	struct coordinate {
		int x = 20;
		int y = 20;
	} gridOffset;
	struct colorForEachDot {
		int r = 255;
		int g = 255;
		int b = 255;
		int a = 255;
	} color;
	
	int _gridLengthInDots;
	int _gridHeightInDots;

	Dot *Origo = nullptr;
	Dot *LastDot = nullptr;
};

