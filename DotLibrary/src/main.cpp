#include "DotLibrary.h"

void pollEvents(DTL::Window &win) {
	SDL_Event evnt;
	if (SDL_PollEvent(&evnt)) {
		win.pollEvent(evnt);
	}
}

using namespace DTL;

int main(int argv, char** argc) {
	Grid gri(100, 100);
	Window myWin("Awesome window", 800, 800, DTL::RESIZABLE_WINDOW);
	myWin.connectGrid(&gri);
	gri.setSpacing(0);
	gri.setDotSize(5);
	gri.setColor(20, 20, 20);
	gri.clear();


	Text testText;
	testText.setColor(200, 200, 200);
	testText.drawText(gri.dot(20, 2), "10, yo");
	while (true) {
		pollEvents(myWin);
		DTL::coordinateTemplate test = gri.dot(0, 0)->getCoords();
		myWin.refresh();
		if (myWin.isClosed())
			return 0;
	}
	return 0;
}