#include "Grid.h"

void pollEvents(Window &window) {
	SDL_Event evnt;

	if (SDL_PollEvent(&evnt)) {
		window.pollEvent(evnt);
	}
}

int main(int argc, char** argv) {

	Grid myGrid(10, 10);
	Dot* thisDot = myGrid.specifyDot(2,2);
	myGrid.SetupWindow("DotLibrary is very cool", 800, 600);

	myGrid.color.g = 20;
	
	int second = 0;
	while (true) {
		pollEvents(*myGrid.window);

		myGrid.drawDefaults();
		if (second == 0) {
			thisDot = thisDot->UP;
			thisDot->color.r = 20;
			thisDot->callDrawMethod();
		}
		else if (second == 1) {
			thisDot = thisDot->UP;
			thisDot->color.r = 20;
			thisDot->callDrawMethod();
		}
		else {
			second = -1;
			thisDot = thisDot->DOWN->DOWN;
		}
		second++;

		SDL_Delay(250);
		myGrid.window->clear();

		if (myGrid.window->isClosed()) {
			break;
		}
	}
	return 0;
}