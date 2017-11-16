#pragma once

#include "window.h"

class Rect {
public:
	Rect(const std::string &image_path);
	~Rect();
	void draw(int w, int h, int x, int y) const; // Draws the rect to screen
private:
	int _w, _h; // rect size
	float _r, _g, _b, _a; // rect color
	SDL_Texture *texture = nullptr; // holds a picture
};