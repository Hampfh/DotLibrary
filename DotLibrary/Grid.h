#pragma once
#include <string>
#include <iostream>
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
	Grid();
	~Grid();
	string setup(int width, int height);
	void visualize();
private:
	Dot *Origin = nullptr;
	Dot *LastDot = nullptr;
};

