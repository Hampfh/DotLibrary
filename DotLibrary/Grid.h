#pragma once
#include <string>
#include <iostream>
#include "Window.h"

using namespace std;

class Dot {
public:
	Dot(int xPos, int yPos);
	~Dot();
public:
	int _xPos;
	int _yPos;
	string representativeColor;
	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;
};

class Grid {
public:
	Grid(int width, int height);
	~Grid();
	void visualize();
	void Grid::SetupWindow(string title, int screenWidth, int screenHeight); 
private:
	string setup(int width, int height);
private:
	Window *mainWindow = nullptr;
	Dot *Origin = nullptr;
	Dot *LastDot = nullptr;
};

