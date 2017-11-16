#include "rect.h"
#include <SDL\SDL_image.h>
#include <iostream>

Rect::Rect(const std::string &image_path)
{
	// The main purpes of a surface is to load a an image
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	// The texture is the object that's gonna be displayed in screen
	texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (!texture) {
		std::cerr << "Failed to create texture.\n";
	}
	SDL_FreeSurface(surface);
}

Rect::~Rect() {
	SDL_DestroyTexture(texture);
}

void Rect::draw(int w, int h, int x, int y) const{
	// Creates a rect and applays all the member variables to it
	SDL_Rect rect = { x, y, w, h };
	
	// If texture already exists then only update if move
	if (texture) {
		SDL_RenderCopy(Window::renderer, texture, nullptr, &rect);
	}
	// If it however does not exist give it a color/texture and render it to the screen
	else {
		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
}
