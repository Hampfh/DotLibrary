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

	Window *window = new Window("DotLibrary is very cool", 700, 200);

	Grid myGrid(200, 10);
	myGrid.gridOffset.x = -700;
	myGrid.gridOffset.y = 10;
	myGrid.dotSize = 10;
	myGrid.spacing = 1;

	myGrid.color.r = 0;
	myGrid.color.g = 0;
	myGrid.color.b = 0;


	Text text;
	

	int temp = 0;

	while (true) {
		pollEvents(*window);
		
		myGrid.drawDefaults();

		text.drawText(myGrid.dot(temp, 2), "hello", 20);
		window->clear();

		temp++;
		SDL_Delay(1);

		if (temp > 130) {
			temp = 0;
		}

		if (window->isClosed()) {
			break;
		}
	}
	return 0;
}