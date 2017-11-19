#include "window.h"
#include <iostream>
#include <SDL\SDL_image.h>
#include <SDL\SDL_ttf.h>

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const std::string &title, int width, int height) :
_title(title), _width(width), _height(height)
{
	_closed = !init();
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

bool Window::init() {

	// Setup SDL Video (screen)
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initalize SDL.h\n";
		return false;
	}

	// Setup image handling
	if (IMG_Init(IMG_INIT_PNG) != 2) {
		std::cerr << "Failed to initialize SDL_image.\n";
		return false;
	}
	// Setup text handling
	if (TTF_Init() == -1) {
		std::cerr << "Failed to initialize SDL_ttf.\n";
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

		// This event get triggered when a key is pressed
	case SDL_KEYDOWN:
		switch (evnt.key.keysym.sym) {
		case SDLK_ESCAPE:
			_closed = true;
			break;
		}

	default:
		break;
	}
}

// Clear render the screen with all it's content
void Window::clear(int r, int g, int b, int a) const {
	// RenderPreset is the final rendering command that renders to screen
	SDL_RenderPresent(renderer);
	// Set background color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	// Clears the screen
	SDL_RenderClear(renderer);
	
}