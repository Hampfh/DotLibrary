#include "dot.h"

Dot::Dot(int xPos, int yPos)  {
	_coordinates.x = xPos;
	_coordinates.y = yPos;
}

Dot::~Dot(){
	
}

void Dot::draw() {
	SDL_Rect rect;
	rect.w = _size.w;
	rect.h = _size.h;
	rect.x = _screenCoordinates.x;
	rect.y = _screenCoordinates.y;

	SDL_SetRenderDrawColor(Window::renderer, _color.r, _color.g, _color.b, 255);
	SDL_RenderFillRect(Window::renderer, &rect);
}

bool Dot::setColor(int r, int g, int b) {
	if (r <= 255 && r >= 0 && g <= 255 && g >= 0 && b <= 255 && b >= 0) {
		_color.r = r;
		_color.g = g;
		_color.b = b;
		return(true);
	}
	else {
		return(false);
	}
}