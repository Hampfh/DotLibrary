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
	Window myWin("Awsome window", 800, 800, DTL_RESIZABLE_WINDOW);
	myWin.connectGrid(&gri);
	gri.setSpacing(0);
	gri.setDotSize(5);
	gri.setColor(20, 20, 20);
	gri.clear();


	Text testText;
	testText.setColor(200, 200, 200);
	while (true) {
		pollEvents(myWin);
		{
			Timer timer("TEXT");
			testText.drawText(gri.dot(20, 2), "10, yo");
		}
		myWin.refresh();
		system("pause");
		if (myWin.isClosed())
			return 0;
	}
	return 0;
}