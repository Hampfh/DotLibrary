#pragma once
#include <string>
#include <iostream>
#include "rect.h"

using namespace std;

class Dot {
public:
	Dot(int xPos, int yPos);
	~Dot();
public:
	int _xPos;
	int _yPos;
	
	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;
	Rect *rect = nullptr;

	struct colors {
		int r, g, b, a; // rect colors
	};
	struct position {
		int x, y; // rect position relative to window
	};
	struct size {
		int w, h; // rect size in pixels
	};
	struct rect_structure_format {
		colors colors;
		position position;
		size size;
	} rect_appearance;
	
};