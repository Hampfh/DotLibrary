#pragma once
#include "Window.h"

class Rect {
public:
	Rect(int w, int h, int x, int y, int r, int g, int b, int a);
	void draw() const;
private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
	~Rect();

};

