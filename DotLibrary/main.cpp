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
	myGrid.offset.x = 20;
	myGrid.offset.y = 10;
	myGrid.dotSize = 15;
	myGrid.spacing = 5;

	myGrid.color.r = 0;
	myGrid.color.g = 0;
	myGrid.color.b = 0;


	Text text;

	int temp = 0;

	myGrid.drawDefaults();
	text.setColor(200, 200, 200, 200);
	text.drawText(myGrid.dot(temp, 2), "Hampfh");
	window->refresh();

	while (true) {

		pollEvents(*window);
		
		

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