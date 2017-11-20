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
	void Grid::SetupWindow(string title, int screenWidth, int screenHeight); 
	void drawGrid(); // <-- under constructction
	Dot *specifyDot(int xCord, int yCord); // <--- under construction
private:
	string setup(int width, int height);
public:
	Window *mainWindow = nullptr;

	struct GridSpecifiers {
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
		int betweenDotDistance = 10;
		int dotSize = 20;
	} GridSpecifications;

private:
	int _gridLengthInDots;
	int _gridHeightInDots;

	Dot *Origo = nullptr;
	Dot *LastDot = nullptr;
};

