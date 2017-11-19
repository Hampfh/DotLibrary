#pragma once
#include "Window.h"

class Rect {
public:
	Rect();
	~Rect();
	void draw(int w, int h, int x, int y, int r, int g, int b, int a) const;
};

