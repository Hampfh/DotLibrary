#pragma once
#include <string>
#include "rect.h"
using namespace std;

class Dot {
public:
	Dot(int xPos, int yPos);
	~Dot();
	void callDrawMethod();
	
public:
	int xGridPosition;
	int yGridPosition;

	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;
	Rect *thisDot = nullptr;

	struct coordinates {
		int x, y;
	} position;
	struct structSize {
		int w;
		int h;
	} size;
	struct colors {
		int r;
		int g;
		int b;
		int a;
	} color;
};

