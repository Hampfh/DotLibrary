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
		} origo;
		struct colorForEachDot {
			int r;
			int g = 50;
			int b = 150;
			int a;
		} color;
		int betweenDotDistance = 10;
		int dotSize = 20;
	} GridSpecifications;

private:
	Dot *Origo = nullptr;
	Dot *LastDot = nullptr;
};

