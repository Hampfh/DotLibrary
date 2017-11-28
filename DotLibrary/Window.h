#pragma once

#include <string>
#include <SDL.h>
#include "Definitions.h"

class Window {
public:
	Window(const std::string &title, int width, int height);
	~Window();
	void pollEvent(SDL_Event &evnt);
	void clear(int r = 0, int g = 0, int b = 0, int a = 255) const;
	inline bool isClosed() const { return _closed; }
private:
	bool init();
private:
	std::string _title;
	int _width = 800;
	int _height = 600;

	bool _closed = false;
	SDL_Window *_window = nullptr;

public:
	static SDL_Renderer *renderer;
};