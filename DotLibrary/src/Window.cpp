#include "window.h"

namespace DTL {

	SDL_Renderer *Window::renderer = nullptr;

	Window::Window(const std::string &title, int width, int height, int flags) {
		if (flags & DTL_HIDE_CMD) {
			FreeConsole();
		}

		DTL_FLAGS = flags;

		_title = title;
		_width = width;
		_height = height;
		_closed = !init();
	}

	Window::~Window() {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(_window);
		SDL_Quit();
	}

	void Window::connectGrid(Grid* gridConnection) {
		if (_firstGrid == nullptr) {
			_firstGrid = gridConnection;
			_lastGrid = gridConnection;
		}
		else {
			_lastGrid->next = gridConnection;
			_lastGrid = _lastGrid->next;
		}
	}

	void Window::detachGrid(Grid* detachGrid) {
		Grid* currentGrid = _firstGrid;
		Grid* prevGrid = currentGrid;
		while (currentGrid != nullptr) {
			if (currentGrid == detachGrid) {
				if (currentGrid == _firstGrid) {
					_firstGrid = _firstGrid->next;
				}
				else if (currentGrid == _lastGrid) {
					_lastGrid = prevGrid;
					_lastGrid->next = nullptr;
				}
				else {
					prevGrid->next = currentGrid->next;
				}
			}
			prevGrid = currentGrid;
			currentGrid = currentGrid->next;
		}
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
			_width, _height, (DTL_FLAGS & DTL_RESIZABLE_WINDOW ? SDL_WINDOW_RESIZABLE : 0) | (DTL_FLAGS & DTL_HIDDEN_WINDOW ? SDL_WINDOW_HIDDEN : 0));

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
		Grid* currentGrid = _firstGrid;
		while (currentGrid != nullptr) {
			currentGrid->drawDefaults();
			currentGrid = currentGrid->next;
		}
		if (!(r <= 255 && r >= 0 && g <= 255 && g >= 0 && b <= 255 && b >= 0))
			return(true);

		// RenderPreset is the final rendering command that renders to screen
		SDL_RenderPresent(renderer);
		// Set background color
		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		// Clears the screen
		SDL_RenderClear(renderer);
		return(false);
	}

}