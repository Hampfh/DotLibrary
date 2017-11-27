#include "Grid.h"
#include "Window.h"
#include "Text.h"
#include <iostream>

void pollEvents(Window &window) {
	SDL_Event evnt;

	if (SDL_PollEvent(&evnt)) {
		window.pollEvent(evnt);
	}
}

int main(int argc, char** argv) {

	Window *window = new Window("DotLibrary is very cool", 1700, 800);

	Grid myGrid(20, 20);
	myGrid.gridOffset.x = 10;
	myGrid.gridOffset.y = 10;
	myGrid.dotSize = 20;
	myGrid.spacing = 0;

	Dot* test = myGrid.dot(1, 2);


	Text text;
	myGrid.drawDefaults();

	text.drawText(test,"Rost",20);
	window->clear();

	while (true) {
		pollEvents(*window);
		
		if (window->isClosed()) {
			break;
		}
	}
	return 0;
}