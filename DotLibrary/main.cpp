#include "Grid.h"
#include "Window.h"

void pollEvents(Window &window) {
	SDL_Event evnt;

	if (SDL_PollEvent(&evnt)) {
		window.pollEvent(evnt);
	}
}

int main(int argc, char** argv) {

	Window *window = new Window("DotLibrary is very cool", 800, 600);

	Grid myGrid(10, 10);
	Dot* thisDot = myGrid.specifyDot(2,2);

	myGrid.color.g = 20;
	
	int second = 0;
	while (true) {
		pollEvents(*window);

		myGrid.drawDefaults();
		if (second == 0) {
			thisDot = thisDot->UP;
			thisDot->color.r = 20;
			thisDot->draw();
		}
		else if (second == 1) {
			thisDot = thisDot->UP;
			thisDot->color.r = 20;
			thisDot->draw();
		}
		else {
			second = -1;
			thisDot = thisDot->DOWN->DOWN;
		}
		second++;

		SDL_Delay(250);
		window->clear();

		if (window->isClosed()) {
			break;
		}
	}
	return 0;
}