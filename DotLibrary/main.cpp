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

	Grid grid(4,4);
	grid.SetupWindow("Test window", 800, 500);

	

	grid.drawGrid();
	grid.mainWindow->clear();
	while (true);
	return 0;
}