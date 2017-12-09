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
	myGrid.setOffset(20, 10);
	myGrid.setDotSize(15);
	myGrid.setSpacing(0);

	myGrid.setColor(100,20,40);

	Dot* TestTWO = myGrid.dot(1, 1);

	TestTWO->getColor().r;

	Text text;

	int temp = 0;
	myGrid.drawDefaults();
	
	text.setColor(200, 200, 200);
	text.drawText(myGrid.dot(temp, 2), "Hampfh");
	window->refresh();

	while (true) {
		myGrid.setSpacing(0);
		pollEvents(*window);
		
		myGrid.drawDefaults();
		text.drawText(myGrid.dot(temp, 2), "Hampfh");
		window->refresh();


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