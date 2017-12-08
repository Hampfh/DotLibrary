#include "dot.h"

Dot::Dot(int xPos, int yPos)  {
	_coordinates.x = xPos;
	_coordinates.y = yPos;
}

Dot::~Dot(){
	
}

void Dot::draw() {
	SDL_Rect rect;
	rect.w = size.w;
	rect.h = size.h;
	rect.x = screenCoordinates.x;
	rect.y = screenCoordinates.y;

	SDL_SetRenderDrawColor(Window::renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(Window::renderer, &rect);
}
