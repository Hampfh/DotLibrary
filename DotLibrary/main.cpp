#include "Grid.h"
#include "Window.h"

void pollEvents(Window &win) {
	SDL_Event evnt;
	if (SDL_PollEvent(&evnt)) {
		win.pollEvent(evnt);
	}
}

int main(int argv, char** argc) {
	Grid gri(100, 100);
	Window myWin("Awsome window", 800, 800, DTL_HIDE_CMD);
	myWin.connectGrid(&gri);
	gri.setSpacing(0);
	gri.setDotSize(5);
	gri.setColor(20, 20, 20);
	gri.clear();
	Text text;
	text.setColor(255, 255, 255);
	text.drawText(gri.dot(20, 30), "TEST");
	while (true) {
		pollEvents(myWin);
		gri.dot(20, 20)->setColor(100, 170, 100);

		myWin.refresh();
		if (myWin.isClosed()) {
			break;
		}
	}
	return 1;
}