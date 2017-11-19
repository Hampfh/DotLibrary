#include "rect.h"

Rect::Rect() {

}

Rect::~Rect()
{
}

void Rect::draw(int w, int h, int x, int y, int r, int g, int b, int a) const {
	SDL_Rect rect;
	rect.w = w;
	rect.h = h;
	rect.x = x;
	rect.y = y;

	SDL_SetRenderDrawColor(Window::renderer, r, g, b, a);
	SDL_RenderFillRect(Window::renderer, &rect);
}
