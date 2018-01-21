#include "window.h"
#include <iostream>

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, int width, int height) :
_title(title), _width(width), _height(height)
{
	// Runnes init();
	_closed = !init();
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Window::init() {

	// Setup SDL Video (screen)
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initalize SDL.h\n";
		return false;
	}

	// Create the window
	_window = SDL_CreateWindow(_title.c_str(),
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_width, _height, 0);
	// Errorcheck
	if (_window == nullptr) {
		std::cerr << "Failed to create window\n";
		return false;
	}
	// Renders the window
	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	// Errorcheck
	if (renderer == nullptr) {
		std::cerr << "Failed to create renderer";
	}

	return true;
}

void Window::pollEvent(SDL_Event &evnt) {
	switch (evnt.type) {
	case SDL_QUIT:
		_closed = true;
		break;
	default:
		break;
	}
}

// Clear render the screen with all it's content
int Window::refresh(int r, int g, int b) const {
	if (!(r <= 255 && r >= 0 && g <= 255 && g >= 0 && b <= 255 && b >= 0)) {
		return(false);
	}
	// RenderPreset is the final rendering command that renders to screen
	SDL_RenderPresent(renderer);
	// Set background color
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	// Clears the screen
	SDL_RenderClear(renderer);
	return(true);
}