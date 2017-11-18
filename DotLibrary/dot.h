#pragma once
#include <string>
#include "rect.h"
using namespace std;

class Dot {
public:
	Dot(int xPos, int yPos);
	~Dot();
private:
	void callDrawMethod();
public:
	int _xPos;
	int _yPos;

	Dot *UP = nullptr;
	Dot *DOWN = nullptr;
	Dot *RIGHT = nullptr;
	Dot *LEFT = nullptr;
	Rect *rect = nullptr;
};

