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
	Grid gri2(100, 100);
	Window myWin("Awsome window", 800, 800, DTL_RESIZABLE_WINDOW);
	myWin.connectGrid(&gri);
	myWin.connectGrid(&gri2);
	gri.setSpacing(0);
	gri.setDotSize(5);
	gri.setColor(20, 20, 20);
	gri.clear();
	gri2.setOffset(5, 5);
	gri2.setSpacing(0);
	gri2.setDotSize(5);
	gri2.setColor(50, 50, 50);
	gri2.clear();

	Text testText;

	while (true) {
		pollEvents(myWin);
		
		testText.drawText(gri.dot(2, 2), "12h50");

		myWin.refresh();
		if (myWin.isClosed())
			return 0;
	}
	return 0;
}