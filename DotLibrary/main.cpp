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

	myGrid.setDotSize(20);

	myGrid.setSpacing(0);

	Text text;
	text.setColor(0,0,200);
	text.createText(myGrid.dot(2, 2), "EDVIN");
	

	while (true) {

		myGrid.drawDefaults();
		text.drawText();
		window->refresh();

		SDL_Delay(1);
		

		if (window->isClosed()) {
			break;
		}
	}
	return 0;
}