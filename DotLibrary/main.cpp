#include "window.h"
#include "Grid.h"
#include "Dot.h"
#include <Windows.h>

void pollEvents(Window &window) {
	SDL_Event evnt;

	if (SDL_PollEvent(&evnt)) {
		window.pollEvent(evnt);
	}
}

int main(int argc, char** argv) {

	//FreeConsole();

	Grid grid(3,3);
	grid.SetupWindow("Test window", 1000, 750);

	grid.GridSpecifications.betweenDotDistance = 40;
	grid.GridSpecifications.dotSize = 20;
	grid.GridSpecifications.gridOffset.x = 50;
	grid.GridSpecifications.gridOffset.y = 50;

	// set standard dot color
	grid.GridSpecifications.color.r = 100;
	grid.GridSpecifications.color.b = 70;
	grid.GridSpecifications.color.g = 30;

	grid.drawGrid();

	Dot* ThisDot = grid.specifyDot(1,3);
	ThisDot->color.g = 6;
	ThisDot->color.r = 2;
	ThisDot->callDrawMethod();
	grid.mainWindow->clear();
	
	while (true) {
		pollEvents(*grid.mainWindow);

		grid.drawGrid();
		Dot* ThisDot = grid.specifyDot(2, 2);
		ThisDot->color.g = 80;
		ThisDot->color.r = 75;
		ThisDot->callDrawMethod();
		grid.mainWindow->clear();

		if (grid.mainWindow->isClosed()) {
			break;
		}
	}

	return 0;
}