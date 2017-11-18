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
	void drawGrid();
	Dot *specifyDot(int xCord, int yCord);
private:
	string setup(int width, int height);
public:
	Window *mainWindow = nullptr;
private:
	Dot *Origin = nullptr;
	Dot *LastDot = nullptr;
};

