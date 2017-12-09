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
