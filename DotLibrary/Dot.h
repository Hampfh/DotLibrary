#pragma once
#include <string>
#include "Window.h"
#include "Definitions.h"

using namespace std;

class Dot {
public:
	Dot(int xPos, int yPos);
	~Dot();
	void draw();
	
public:
	int xGridPosition, yGridPosition; // Grid coordinates

	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;

	struct coordinates {
		int x, y; // Screen coordinates
	} position;
	struct structSize {
		int w;
		int h;
	} size;
	colorTemplate color;
};

