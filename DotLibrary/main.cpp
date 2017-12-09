#include "Grid.h"
#include "Window.h"
#include "Text.h"
#include <iostream>
#include "Definitions.h"

void pollEvents(Window &window) {
	SDL_Event evnt;

	if (SDL_PollEvent(&evnt)) {
		window.pollEvent(evnt);
	}
}

int main(int argc, char** argv) {
	Window *window = new Window("DotLibrary is very cool", 800, 800);

	Grid myGrid(200, 10);

	while (true) {

		myGrid.drawDefaults();
		window->refresh();

		SDL_Delay(1);
		

		if (window->isClosed()) {
			break;
		}
	}
	return 0;
}