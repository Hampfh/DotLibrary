#pragma once

#include <string>
#include <SDL\SDL.h>

class Window {
public:
	Window(const std::string &title, int width, int height);
	~Window();
	void pollEvent(SDL_Event &evnt);
	void clear() const;
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