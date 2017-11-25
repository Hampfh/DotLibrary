#include "dot.h"

Dot::Dot(int xPos, int yPos) :
xGridPosition(xPos), yGridPosition(yPos) {

}


Dot::~Dot(){
	delete UP;
	delete RIGHT;
	delete DOWN;
	delete LEFT;
}

void Dot::draw() {
	SDL_Rect rect;
	rect.w = size.w;
	rect.h = size.h;
	rect.x = position.x;
	rect.y = position.y;

	SDL_SetRenderDrawColor(Window::renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(Window::renderer, &rect);
}
