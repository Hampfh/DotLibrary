#include "rect.h"

Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a) :
_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{

}

Rect::~Rect()
{
}

void Rect::draw() const {
	SDL_Rect rect;
	rect.w = _w;
	rect.h = _h;
	rect.x = _x;
	rect.y = _y;

	SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
	SDL_RenderFillRect(Window::renderer, &rect);
}
