#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <SDL.h>
#include "Definitions.h"
#include "Dot.h"
#include "Grid.h"

class Grid;

enum flags {
	DTL_HIDE_CMD = 0x01,
};

class Window {
public:
	/**
	@Desciption: Creates a default window
	title = name of the window
	width = width of window in pixels
	height = height of window in pixels
	*/
	Window(const std::string &title, int width, int height, int flags = 0);
	~Window();
	/**
	@Description: Connects the grid to the window renderer. When a grid is connected it will be rendered together with refresh
	@Return type: void
	*/
	void connectGrid(Grid* gridConnection);
	/**
	@Description: Detaches the grid from the window renderer. Grid will no longer be rendered together with window refresh
	@Return type: void
	*/
	void detachGrid(Grid* gridConnection);
	/**
	@Description: Returns the renderer for the window class
	@Return type: SDL_Renderer*
	*/
	inline SDL_Renderer *getRenderer() { return (renderer); };	
	/**
	@Desciption: Requires an SDL_Event input
	*/
	void pollEvent(SDL_Event &evnt);
	/**
	@Desciption: Takes all waiting draw calls and displays them on the screen. Function also got support for custom backgroud color:
	Set background color by assigning RGB values. The function will return true if executed correctly otherwise false
	r minimum value is 0 : maximum value is 255
	g minimum value is 0 : maximum value is 255
	b minimum value is 0 : maximum value is 255
	@Return type: bool
	*/
	int refresh(int r = 0, int g = 0, int b = 0) const;
	/**
	@Desciption: Returns true if user have clicked on the exit button on the window
	@Requires: Pollevent function need to run continuously
	@Return type: bool
	*/
	inline bool isClosed() const { return _closed; }
private:
	bool init();
private:
	friend class Dot;

	std::string _title;
	int _width = 800;
	int _height = 600;

	bool _closed = false;
	SDL_Window *_window = nullptr;
	Grid* _firstGrid = nullptr;
	Grid* _lastGrid = nullptr;

	static SDL_Renderer *renderer;
};